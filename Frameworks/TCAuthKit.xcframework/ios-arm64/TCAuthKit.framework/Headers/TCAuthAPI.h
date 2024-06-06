//
//  TCAuthAPI.h
//  TCAuthKit
//
//  Created by dong on 2024/5/28.
//

#import <Foundation/Foundation.h>
#import <TCAuthKit/TCAuthAPIObject.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - TCAuthAPIDelegate
/*! @brief 接收并处理来自虎盾终端程序的事件消息
 *
 * 接收并处理来自虎盾终端程序的事件消息，期间虎盾界面会切换到第三方应用程序。
 * TCAuthAPIDelegate 会在handleOpenURL:delegate:中使用并触发。
 */
@protocol TCAuthAPIDelegate <NSObject>
@optional

/*! @brief 发送一个startSSOLogin后，收到虎盾的回应
 *
 * @param resp 具体的回应内容
 */
- (void)onResp:(TCBaseResp *)resp;

@end


@interface TCAuthAPI : NSObject

/**
 第三方APP向钉钉注册申请的appId.
 
 第三方应用程序需要在程序启动时调用. @note 请在主线程中调用此方法.
 
 @param clientID 在钉钉开放平台申请的应用ID.
 
 @retrun YES 注册成功. NO 注册失败.
 */
+ (BOOL)registerApp:(NSString *)clientID;


/*! @brief 处理虎盾通过URL启动App时传递的数据
 *
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @param url 虎盾启动第三方应用时传递过来的URL
 * @param delegate  WWKApiDelegate对象，用来接收虎盾触发的消息。
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)handleOpenURL:(NSURL *)url delegate:(id<TCAuthAPIDelegate>) delegate;

/*! @brief 检查虎盾是否已被用户安装
 *
 * @return 虎盾已安装返回YES，未安装返回NO。
 * @note 由于iOS系统的限制，在iOS9及以上系统检测虎盾是否安装，需要将虎盾的scheme"tigersec"及"tigersec-sso"添加到工程的Info.plist中的LSApplicationQueriesSchemes白名单里，否则此方法总是会返回NO。
 * 详情参考 https://developer.apple.com/documentation/uikit/uiapplication/1622952-canopenurl
 */
+ (BOOL)isAppInstalled;

/**
 检测设备安装的虎盾是否支持虎盾SSO授权.
 
 @return YES 设备安装的虎盾客户端支持虎盾SSO授权. NO 设备安装的虎盾客户端不支持虎盾SSO授权.
 */
+ (BOOL)isSupportSSO;


/*! @brief 获取当前虎盾SDK的版本号
 *
 * @return 返回当前虎盾SDK的版本号
 */
+ (NSString *)getApiVersion;

/*! @brief 打开虎盾
 *
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)openApp;

/*!
 * @brief 启动登录流程。
 * @param ssoReq 认证请求类
 * @see TCSSOReq
 */
+ (void)startSSOLogin:(TCSSOReq *)ssoReq;

@end

NS_ASSUME_NONNULL_END
