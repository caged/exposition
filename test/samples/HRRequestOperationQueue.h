/**
 * The object which all requests are routed through.  You shouldn't need to use 
 * this class directly, but instead use HRRestModel which wraps the method 
 * of this class neatly.
 */
@interface HRRequestOperation : NSOperation {
    NSObject        <HRResponseDelegate>*_delegate;
    NSURLConnection *_connection;
    NSMutableData   *_responseData;
    NSString        *_path;
    NSDictionary    *_options;
    NSTimeInterval  _timeout;
    HRRequestMethod _requestMethod;
    id              _formatter;
    id              _object;
    BOOL _isFinished;
    BOOL _isExecuting;
    BOOL _isCancelled;
}

/**
 * The HRResponseDelegate responsible for handling the success and failure of 
 * a request.
 */
@property (nonatomic, readonly, assign) NSObject <HRResponseDelegate>*delegate;
 
/**
 * Sets the length of time in seconds before a request will timeout.
 * This defaults to <tt>30.0</tt>.
 */
@property (nonatomic, assign) NSTimeInterval timeout;

/**
 * This defaults to HRRequestMethodGet.  Valid options are ::HRRequestMethod.
 */
@property (nonatomic, assign) HRRequestMethod requestMethod;

/**
 * If you provide a relative path here, you must set the baseURL option.
 * If given a full url this will overide the baseURL option.
 */
@property (nonatomic, copy) NSString *path;

/**
 * This needs documented
 */
@property (nonatomic, retain) NSDictionary *options;

/**
 * Currently, only JSON is supported.
 */
@property (nonatomic, readonly, retain) id formatter;

/**
 * Returns an HRRequestOperation
 */
+ (HRRequestOperation *)requestWithMethod:(HRRequestMethod)method path:(NSString*)urlPath options:(NSDictionary*)requestOptions object:(id)obj;
@end
