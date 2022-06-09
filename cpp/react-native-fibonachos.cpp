#include "react-native-fibonachos.h"
// sstream contains functions to manipulate strings in C++
#include <sstream>
#include <climits>
#import "sodium.h"

using namespace facebook;

void installFibo(jsi::Runtime& jsiRuntime) {
  auto compute = jsi::Function::createFromHostFunction(
    jsiRuntime, // JSI runtime instance
    jsi::PropNameID::forAscii(jsiRuntime, "compute"), // Internal function name
    1,
    // This is a C++ lambda function, the empty [] at the beginning is used to capture pointer/references so that they don't get de-allocated
    // Then you get another instance of the runtime to use inside the function, a "this" value from the javascript world, a pointer to the arguments (you can treat it as an array) and finally a count for the number of arguments
    // Finally the function needs to return a jsi::Value (read JavaScript value)
    [](jsi::Runtime& runtime, const jsi::Value& thisValue, const jsi::Value* arguments, size_t count) -> jsi::Value {

      // the jsi::Value has a lot of helper methods for you to manipulate the data
      if(!arguments[0].isNumber()) {
        jsi::detail::throwJSError(runtime, "Cannot compute fibonacci series without a rank");
      }

      double n = arguments[0].asNumber();
			if(n < 2) return jsi::String::createFromUtf8(runtime, "1 nacho");
			unsigned long long prev = 1;
			unsigned long long curr = 1;
			unsigned long long tmp = 0;
			for(int i=1; i<n; i++) {
        if (curr > ULLONG_MAX - prev) {
          return jsi::String::createFromUtf8(runtime, "too many nachos for this planet");
        }
				tmp = curr;
				curr += prev;
				prev = tmp;
			}
      std::stringstream result("");
      result << curr << " nachos";
      return jsi::String::createFromUtf8(runtime, result.str());
    }
  );

  auto randomNumber = jsi::Function::createFromHostFunction(
      jsiRuntime, // JSI runtime instance
      jsi::PropNameID::forAscii(jsiRuntime, "randomNumber"), // Internal function name
      1,
      // This is a C++ lambda function, the empty [] at the beginning is used to capture pointer/references so that they don't get de-allocated
      // Then you get another instance of the runtime to use inside the function, a "this" value from the javascript world, a pointer to the arguments (you can treat it as an array) and finally a count for the number of arguments
      // Finally the function needs to return a jsi::Value (read JavaScript value)
      [](jsi::Runtime& runtime, const jsi::Value& thisValue, const jsi::Value* arguments, size_t count) -> jsi::Value {

        return jsi::Value((int)randombytes_random());
      }
    );

  // Registers the function on the global object
  jsiRuntime.global().setProperty(jsiRuntime, "computeFibo", std::move(compute));
  jsiRuntime.global().setProperty(jsiRuntime, "randomNumber", std::move(randomNumber));
}

void cleanUpFibo() {
  // intentionally left blank
}
