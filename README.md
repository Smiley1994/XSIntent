# XSIntent
一款简单的页面间跳转，通信工具。

# Installation
1. Add pod "XSIntent" to your Podfile.
2. Run pod install or pod update.

# Usage
### Open Page
```
/// Open A 
XSIntent *intent = [[XSIntent alloc] initWithClassName:@"Controller Class Name"];
[intent setObject:@"aaaa" forKey:@"Key"];
[self openIntent:intent withRequestCode:9999];
```
or
```
[self openClass:@"Controller Class Name"];
```
### Close Page
```
[self finish];
```
or
```
[self finishWithResultCode:RESULT_OK andResultData:@{@"aaa":@"111"}];
```

### UIViewControllerIntentDelegate
```
/// 将要打开页面
/// - Parameters:
///   - viewController: ViewController
///   - intent: Intent 对象
- (XSError *)willOpenViewController:(__kindof UIViewController *)viewController withIntent:(XSIntent *)intent {
    // 特殊页面处理
    if ([intent.className isEqualToString:@"TempController"]) {
        
        return [XSError ok];
    }
    // 默认
    return [super willOpenViewController:viewController withIntent:intent];
}

/// 将要关闭页面
/// - Parameters:
///   - viewController: ViewController
///   - intent: Intent 对象
- (void)willCloseViewController:(__kindof UIViewController *)viewController withIntent:(XSIntent *)intent {
    // 特殊页面处理
    if ([intent.className isEqualToString:@"TempController"]) {
        
    } else {
        // 默认
        [super willCloseViewController:viewController withIntent:intent];
    }
}

/// 页面回调
/// - Parameters:
///   - viewController: ViewController
///   - requestCode: ViewController 打开的标记值
///   - resultCode: ViewController 关闭类型
///   - resultData: ViewController 关闭返回参数
- (void)onViewController:(__kindof UIViewController *)viewController ofRequestCode:(NSInteger)requestCode finshedWithResult:(NSInteger)resultCode andResultData:(NSDictionary *)resultData {
    
    if (resultCode == RESULT_OK) {
//        /// have request code
//        switch (requestCode) {
//            case 00000: {/// doing ....}
//                break;
//            default:
//                break;
//        }
    } else if (resultCode == RESULT_CANCELED) {
        /// 取消操作
        ///
    } else {
        [super onViewController:viewController ofRequestCode:requestCode finshedWithResult:resultCode andResultData:resultData];
    }
}
```
