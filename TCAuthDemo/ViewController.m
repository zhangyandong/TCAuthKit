//
//  ViewController.m
//  TCAuthDemo
//
//  Created by dong on 2024/5/28.
//

#import "ViewController.h"
#import <TCAuthKit/TCAuthKit.h>

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *authInfoLabel;
@property (weak, nonatomic) IBOutlet UISwitch *dependTunnelSwitch;

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  self.title = [NSString stringWithFormat:@"虎盾SDK（%@）", [TCAuthAPI getApiVersion]];
  BOOL isAppInstalled = [TCAuthAPI isAppInstalled];
  BOOL isSupportSSO = [TCAuthAPI isSupportSSO];
  self.authInfoLabel.text = [NSString stringWithFormat:@"虎盾是否安装：%d \n虎盾是否支持SSO：%d", isAppInstalled, isSupportSSO];
}


- (IBAction)startSSOLogin:(id)sender {
  TCSSOReq *ssoReq = [[TCSSOReq alloc] init];
  ssoReq.dependTunnel = self.dependTunnelSwitch.on;
  [TCAuthAPI startSSOLogin:ssoReq];
}

@end
