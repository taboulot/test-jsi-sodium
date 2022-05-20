#import <React/RCTBridgeModule.h>
#import "react-native-fibonachos.h"

@interface Fibonachos : NSObject <RCTBridgeModule>

@property (nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
