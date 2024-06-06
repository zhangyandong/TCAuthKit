//
//  TCAuthAPIObject.h
//  TCAuthKit
//
//  Created by dong on 2024/5/30.
//

#import <Foundation/Foundation.h>

/**
 错误码.
 */
typedef NS_ENUM(NSInteger, TCAuthAPIErrorCode)
{
  TCAuthAPISuccess               =  0,   /**< 成功*/
  TCAuthAPIErrorCodeUserCancel   = -1,   /**< 用户取消*/
  TCAuthAPIErrorCodeAuthDeny     = -2,   /**< 授权失败*/
};

NS_ASSUME_NONNULL_BEGIN

/**
 发送请求类的基类.
 */
@interface TCBaseReq : NSObject
@end

/**
 发送认证请求类.
 */
@interface TCSSOReq : TCBaseReq
/*!
dependTunnel 是否依赖隧道；默认为NO登录后就回调结果；YES：则会登录成功并等待隧道链接结果，会回调隧道状态；
 */
@property (nonatomic, assign) BOOL dependTunnel;
/**
 state 第三方应用传入的值，登录成功后会透传给第三方应用
 */
@property (nonatomic, copy, nullable) NSString *state;
@end


/**
 响应类的基类
 */
@interface TCBaseResp : NSObject
/// 错误码
@property (nonatomic, assign) TCAuthAPIErrorCode errorCode;
/// 错误提示
@property (nonatomic, copy) NSString *errorMessage;
@end


/**
 钉钉客户端处理完第三方应用的认证申请后向第三方应用回送的处理结果
 */
@interface TCSSOResp : TCBaseResp
/**
 临时授权码
 */
@property (nonatomic, copy, nullable) NSString *authCode;
/**
 透传的state
 */
@property (nonatomic, copy, nullable) NSString *state;

/**
 隧道是否已链接
 dependTunnel为YES，这个参数才有意义
 */
@property (nonatomic, assign) BOOL tunnelConnected;

@end


@interface TCAuthAPIObject : NSObject

@end

NS_ASSUME_NONNULL_END
