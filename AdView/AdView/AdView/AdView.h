//
//  AdView.h
//  广告循环滚动效果
//
//  Created by QzydeMac on 14/12/24.
//  Copyright (c) 2014年 Qzy. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef NS_ENUM(NSUInteger, UIPageControlShowStyle)
{
    /**
     *  @author ZY, 15-04-26
     *
     *  不显示PageControl
     */
    UIPageControlShowStyleNone,//default
    UIPageControlShowStyleLeft,
    UIPageControlShowStyleCenter,
    UIPageControlShowStyleRight,
};

typedef NS_ENUM(NSUInteger, AdTitleShowStyle)
{
    /**
     *  @author ZY, 15-04-26
     *
     *  不显示标题
     */
    AdTitleShowStyleNone,
    AdTitleShowStyleLeft,
    AdTitleShowStyleCenter,
    AdTitleShowStyleRight,
};

@interface AdView : UIView<UIScrollViewDelegate>
{
    UILabel * _centerAdLabel;
    CGFloat _adMoveTime;
}

/**
 *  @author ZY, 15-04-26
 *
 *  @brief  这个计时器需要特殊处理,否则会照成内存泄露
 */
@property (assign, nonatomic) NSTimer *moveTimer;
@property (retain,nonatomic,readonly) UIScrollView * adScrollView;
@property (retain,nonatomic,readonly) UIPageControl * pageControl;
@property (retain,nonatomic,readonly) NSArray * imageLinkURL;
@property (retain,nonatomic,readonly) NSArray * adTitleArray;
/**
 *  @author ZY, 15-05-17
 *
 *  设置page显示位置
 */
@property (assign,nonatomic) UIPageControlShowStyle  PageControlShowStyle;
/**
 *  @author ZY, 15-05-17
 *
 *  设置标题对应的位置
 */
@property (assign,nonatomic,readonly) AdTitleShowStyle  adTitleStyle;

/**
 *  @author ZY, 15-05-17
 *
 *  设置占位图片
 */
@property (nonatomic,strong) UIImage * placeHoldImage;

/**
 *  @author ZY, 15-05-17
 *
 *  是否需要定时循环滚动
 */
@property (nonatomic,assign) BOOL isNeedCycleRoll;



/**
 *  @author ZY, 15-04-26
 *
 *  @brief  图片移动计时器
 */
@property (nonatomic,assign) CGFloat  adMoveTime;
/**
 *  @author ZY, 15-04-26
 *
 *  @brief  在这里修改Label的一些属性
 */
@property (nonatomic,strong,readonly) UILabel * centerAdLabel;

/**
 *  @author ZY, 15-04-26
 *
 *  @brief  给图片创建点击后的回调方法
 */
@property (nonatomic,strong) void (^callBack)(NSInteger index,NSString * imageURL);

/**
 *  @author ZY, 15-04-26
 *
 *  @brief  设置每个图片下方的标题
 *
 *  @param adTitleArray 标题数组
 *  @param adTitleStyle 标题显示风格
 */
- (void)setAdTitleArray:(NSArray *)adTitleArray withShowStyle:(AdTitleShowStyle)adTitleStyle;

/**
 *  @author ZY, 15-04-26
 *
 *  @brief  创建AdView对象
 *
 *  @param frame                设置Frame
 *  @param imageLinkURL         图片链接地址数组,数组的每一项均为字符串
 *  @param PageControlShowStyle PageControl显示位置
 *  @param object 控件在那个类文件中
 *  @return 广告视图
 */
//+ (id)adScrollViewWithFrame:(CGRect)frame imageLinkURL:(NSArray *)imageLinkURL pageControlShowStyle:(UIPageControlShowStyle)PageControlShowStyle;

/**
 *  @author ZY, 15-04-26
 *
 *  @brief  创建AdView对象
 *
 *  @param frame                设置Frame
 *  @param imageLinkURL         图片链接地址数组,数组的每一项均为字符串
 *  @param imageName            占位图片
 *  @param PageControlShowStyle PageControl显示位置
 *  @param object 控件在那个类文件中
 *  @return 广告视图
 */
+ (id)adScrollViewWithFrame:(CGRect)frame imageLinkURL:(NSArray *)imageLinkURL placeHoderImageName:(NSString *)imageName pageControlShowStyle:(UIPageControlShowStyle)PageControlShowStyle;

/**
 *  @author ZY, 15-04-26
 *
 *  @brief  创建AdView对象
 *
 *  @param frame                设置Frame
 *  @param imageLinkURL         本地图片名称数组
 *  @param PageControlShowStyle PageControl显示位置
 *  @param object 控件在那个类文件中
 *  @return 广告视图
 */
+ (id)adScrollViewWithFrame:(CGRect)frame localImageLinkURL:(NSArray *)imageLinkURL pageControlShowStyle:(UIPageControlShowStyle)PageControlShowStyle;
@end
