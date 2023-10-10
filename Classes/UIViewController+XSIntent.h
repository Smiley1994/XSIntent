//
//  UIViewController+XSIntent.h
//  XSIntent
//
//  Created by mt230824 on 2023/10/9.
//

#import <UIKit/UIKit.h>

#import "XSIntent.h"
#import "XSError.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSInteger const RESULT_OK;
FOUNDATION_EXTERN NSInteger const RESULT_CANCELED;

@interface UIViewController (XSIntent) <UIViewControllerIntentDelegate>

/// 打开页面
/// - Parameter className: 类名
- (XSError *)openClass:(NSString *)className;

/// 打开页面
/// - Parameter intent: Intent 对象
- (XSError *)openIntent:(XSIntent *)intent;

/// 打开页面
/// - Parameters:
///   - intent: Intent 对象
///   - requestCode: 打开页面的标记值
- (XSError *)openIntent:(XSIntent *)intent withRequestCode:(NSInteger)requestCode;

/// 关闭页面
/// 默认关闭类型: RESULT_CANCELED
- (void)cancel;

/// 关闭页面
/// 默认关闭类型: RESULT_CANCELED
- (void)finish;

/// 关闭页面
/// - Parameter resultCode: 关闭类型
- (void)finishWithResultCode:(NSInteger)resultCode;

/// 关闭页面
/// - Parameters:
///   - resultCode: 关闭类型
///   - resultData: 关闭返回参数
- (void)finishWithResultCode:(NSInteger)resultCode andResultData:(NSDictionary *)resultData;

/// 添加 Intent 属性
- (void)setIntent:(XSIntent *)intent;
- (XSIntent *)intent;

/// 添加 closed 属性
- (void)setClosed:(BOOL)closed;
- (BOOL)isClosed;

@end

NS_ASSUME_NONNULL_END
