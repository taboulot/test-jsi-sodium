package com.fibonachos;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

public class FibonachosModule extends ReactContextBaseJavaModule {

    private static native void initialize(long jsiPtr);
    private static native void destroy();

    public FibonachosModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return "Fibonachos";
    }

    static {
        try {
            // Used to load the 'native-lib' library on application startup.
            System.loadLibrary("fibonachos");
        } catch (Exception ignored) {
        }
    }

    @NonNull
    @Override
    public void initialize() {
        super.initialize();
        FibonachosModule.initialize(
            this.getReactApplicationContext().getJavaScriptContextHolder().get()
        );
    }

    @Override
    public void onCatalystInstanceDestroy() {
        FibonachosModule.destroy();
    }
}
