# TMReachability

网络状态监听库

## Requirements

iOS 8.0

## Installation

TMReachability is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
source 'https://github.com/Tovema-iOS/Specs.git'
pod "TMReachability", '~> 1.0'
```

## Usage

``` Objective-C
// 引用头文件
#import <TMReachability/TMReachability.h>

// 初始化
[TMReachabilityHelper checkReachability];

// 获取网络状态：
NSLog(@"%@", TMReachabilityHelper.isReachable ? @"网络正常" : @"网络异常");
NSLog(@"%@", TMReachabilityHelper.isWiFiReachable ? @"Wifi 联网" : @"非 Wifi 联网");
NSLog(@"%@", TMReachabilityHelper.isWWANReachable ? @"蜂窝联网" : @"非蜂窝联网");
NSLog(@"%@", @(TMReachabilityHelper.currentStatus));

// 监听网络状态变化
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onNetworkChange:) name:TMReachabilityChangedNotification object:nil];
```

## Author

CodingPub, lxb_0605@qq.com

## License

TMReachability is available under the MIT license. See the LICENSE file for more info.
