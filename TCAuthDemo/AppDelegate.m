//
//  AppDelegate.m
//  TCAuthDemo
//
//  Created by dong on 2024/5/28.
//

#import "AppDelegate.h"
#import <TCAuthKit/TCAuthKit.h>

@interface AppDelegate () <TCAuthAPIDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Override point for customization after application launch.
  [TCAuthAPI registerApp:@"oY2GWMHEP3ILRIOhWU7VUPri6RX3VQjl"];
  return YES;
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
  NSLog(@"openURL-----%@", url);
  [TCAuthAPI handleOpenURL:url delegate:self];
  return YES;
}


- (void)onResp:(TCBaseResp *)resp {
  TCSSOResp *ssss = (TCSSOResp *)resp;
  UIAlertController *alertVC = [UIAlertController alertControllerWithTitle:@"授权结果" message:[NSString stringWithFormat:@"%@--%@", ssss.errorMessage, ssss.authCode] preferredStyle:UIAlertControllerStyleAlert];
  UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:nil];
  [alertVC addAction:cancelAction];
  [self.window.rootViewController presentViewController:alertVC animated:YES completion:nil];
}


#pragma mark - UISceneSession lifecycle
//- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options  API_AVAILABLE(ios(13.0)) API_AVAILABLE(ios(13.0)){
//  // Called when a new scene session is being created.
//  // Use this method to select a configuration to create the new scene with.
//  return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
//}
//
//
//- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions  API_AVAILABLE(ios(13.0)){
//  // Called when the user discards a scene session.
//  // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
//  // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
//}


@end
