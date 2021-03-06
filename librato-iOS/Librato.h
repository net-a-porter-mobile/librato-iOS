//
//  Librato.h
//  Librato-iOS
//
//  Created by Adam Yanalunas on 9/30/13.
//  Copyright (c) 2013 Amco International Education Services, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LibratoClient.h"
#import "LibratoException.h"
#import "LibratoGaugeMetric.h"
#import "LibratoMetric.h"
#import "LibratoPersister.h"


extern NSString *const LIBRATO_LOCALIZABLE;


@class LibratoConnection, LibratoClient;


@interface Librato : NSObject


typedef void (^LibratoMetricContext)(Librato *librato);
typedef void (^LibratoNotificationContext)(NSNotification *notification);


@property (nonatomic, strong) LibratoClient *client;
@property (nonatomic, strong) NSString *prefix;
@property (nonatomic, strong) dispatch_queue_t queue;

+ (NSDate *)minimumMeasureTime;

- (instancetype)initWithEmail:(NSString *)email token:(NSString *)apiKey prefix:(NSString *)prefix;

- (void)add:(id)metrics;
- (NSString *)APIEndpoint;
- (void)setAPIEndpoint:(NSString *)APIEndpoint;
- (void)authenticateEmail:(NSString *)emailAddress APIKey:(NSString *)apiKey;
- (LibratoClient *)client;
- (LibratoConnection *)connection;
- (NSString *)customUserAgent;
- (void)setCustomUserAgent:(NSString *)userAgent;
- (void)getMetric:(NSString *)name options:(NSDictionary *)options;
- (void)getMeasurements:(NSString *)named options:(NSDictionary *)options;
- (NSArray *)groupNamed:(NSString *)name valued:(NSDictionary *)values;
- (void)groupNamed:(NSString *)name context:(LibratoMetricContext)context;
- (id)listenForNotification:(NSString *)named context:(LibratoNotificationContext)context;
- (NSString *)persistence;
- (void)setPersistence:(NSString *)persistence;
- (id<LibratoPersister>)persister;
- (void)setSubmitSuccessBlock:(ClientSuccessBlock)successBlock;
- (void)setSubmitFailureBlock:(ClientFailureBlock)failureBlock;
- (void)submit:(id)metrics;
- (void)trackDefaultMetrics;
- (void)updateMetricsNamed:(NSString *)name options:(NSDictionary *)options;
- (void)updateMetrics:(NSDictionary *)metrics;


@end
