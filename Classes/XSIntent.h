//
//  XSIntent.h
//  XSIntent
//
//  Created by mt230824 on 2023/10/9.
//

#import <Foundation/Foundation.h>

@class XSIntent;
@class XSError;

NS_ASSUME_NONNULL_BEGIN

@protocol UIViewControllerIntentDelegate <NSObject>

@optional;

/// 将要打开页面
/// - Parameters:
///   - viewController: ViewController
///   - intent: Intent 对象
- (XSError*)willOpenViewController:(__kindof UIViewController *)viewController withIntent:(XSIntent *)intent;

/// 将要关闭页面
/// - Parameters:
///   - viewController: ViewController
///   - intent: Intent 对象
- (void)willCloseViewController:(__kindof UIViewController *)viewController withIntent:(XSIntent *)intent;

/// 页面回调
/// - Parameters:
///   - viewController: ViewController
///   - requestCode: ViewController 打开的标记值
///   - resultCode: ViewController 关闭类型
///   - resultData: ViewController 关闭返回参数
- (void)onViewController:(__kindof UIViewController *)viewController ofRequestCode:(NSInteger)requestCode finshedWithResult:(NSInteger)resultCode andResultData:(NSDictionary *)resultData;

@end

typedef NS_ENUM(NSInteger,OpenViewControllerMethod){
    OPEN_METHOD_PUSH,
    OPEN_METHOD_POP,
    OPEN_METHOD_SHOW
};

@interface XSIntent : NSObject

/// 是否 push 导航栏
@property (nonatomic, assign) BOOL useNavigationToPush;
/// 是否隐藏 TabBar
@property (nonatomic, assign) BOOL hidesBottomBarWhenPushed;
///
@property (nonatomic, assign) BOOL isRequest;
/// 标记值
@property (nonatomic, assign) NSInteger requestCode;
/// 是否开启 push 动画
@property (nonatomic, assign) BOOL animated;
/// 类名
@property (nonatomic, strong) NSString *className;
/// 打开页面方式 push / pop / show
@property (nonatomic, assign) OpenViewControllerMethod method;
/// intent delegate
@property (nonatomic, weak) id<UIViewControllerIntentDelegate> delegate;

/// intent data
- (NSDictionary *)intentData;
/// set intent data
- (void)setObject:(id)object forKey:(NSString *)key;
/// get intent data value
- (id)objectForKey:(NSString *)key;

/// init method
- (instancetype)initWithClassName:(NSString *)className; //NS_DESIGNATED_INITIALIZER;
/// init method
+ (instancetype)intentWithClassName:(NSString *)className;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

@end

NS_ASSUME_NONNULL_END
