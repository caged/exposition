/**
 * This is some documentation for SampleClass.
 * 
 * It can span multiple lines as long as it's directly above the class it documents.
 *
 * @implementation Tweet
 * @synthesize screenName;
 * @synthesize name;
 * @synthesize text;
 * @synthesize location;
 * 
 * // Set default options here
 * + (void)initialize {
 *     [self setDelegate:self];
 *     [self setBaseURL:[NSURL URLWithString:@"http://twitter.com"]];
 * }
 * 
 * - (void)initWithDictionary:(NSDictionary *)dict {
 *     if(self = [super init]) {
 *         [self setScreenName:[dict valueForKeyPath:@"user.screen_name"]];
 *         [self setName:[dict valueForKeyPath:@"user.name"]];
 *         [self setLocation:[dict valueForKeyPath:@"user.location"]];
 *         [self setText:[dict valueForKey:@"text"]];
 *     }
 * 
 *     return self;
 * }
 * 
 * // NOTE: The `delegate` object isn't neccissary here, but there is an important reason why
 * // I'm using this approach.  I want to give my controller fully initialized models instead of 
 * // raw NSDIctionary  objects.  On that note I pass the controller as the <tt>object</tt> to the 
 * // request so I can call back to it in the delegate methods handling the responses.
 * + (id)timelineForUser:(NSString *)user delegate:(id)delegate {
 *     NSDictionary *params = [NSDictionary dictionaryWithObject:user forKey:@"screen_name"];
 *     NSDictionary *opts = [NSDictionary dictionaryWithObject:params forKey:@"params"];
 * 
 *     [self getPath:@"/statuses/user_timeline.json" withOptions:opts object:delegate];
 * }
 * 
 * + (id)publicTimelineWithDelegate:(id)delegate {
 *     [self getPath:@"/statuses/public_timeline.json" withOptions:nil object:delegate];
 * }
 * 
 * #pragma mark - HRRequestOperation Delegates
 * + (void)restConnection:(NSURLConnection *)connection didFailWithError:(NSError *)error object:(id)object {
 *     // Handle connection errors.  Failures to connect to the server, etc.
 * }
 * 
 * + (void)restConnection:(NSURLConnection *)connection didReceiveError:(NSError *)error response:(NSHTTPURLResponse *)response object:(id)object {
 *     // Handle invalid responses, 404, 500, etc.
 * }
 * 
 * + (void)restConnection:(NSURLConnection *)connection didReceiveParseError:(NSError *)error responseBody:(NSString *)string {
 *     // Request was successful, but couldn't parse the data returned by the server. 
 * }
 * 
 * // Given I've passed the controller as the <tt>object</tt> here, I can call any method I want to on it
 * // giving it a collection of models I've initialized.
 * + (void)restConnection:(NSURLConnection *)connection didReturnResource:(id)resource  object:(id)object {
 *     NSMutableArray *tweets = [[[NSMutableArray alloc] init] autorelease];
 * 
 *     for(id item in resource) {
 *         [tweets addItem:[[Tweet alloc] initWithDictionary:item]];
 *     }
 * 
 *     [object performSelector:@selector(tweetsLoaded:) withObject:tweets];
 * }
 * @end
 */
@interface SampleClass : NSObject
    <EXSomeProtocol, EXSomeOtherProtocol, EXSomeDifferentProtocol>
{
    NSString *_someString;
    CGFloat someFloat;
    id fooBar;
    id<Bob, Jane, Tom> someConformingObject;
}

@property (nonatomic, retain) NSString *someString;
@property (readonly, nonatomic) NSArray *someArray;
@property (nonatomic, assign) CGFloat someFloat;
@property NSInteger someInt;
@property (nonatomic, retain) IBOutlet NSButton *someButton;
@property (nonatomic, assign, getter=isSomethingTrue, setter=comfirmSomethingIsTrue) BOOL somethingTrue;
@property(retain) __attribute__((NSObject)) CFDictionaryRef myDictionary;
@property (nonatomic, retain) __weak Link *parent;
@property (nonatomic, retain) __strong Link *parent;
@property(nonatomic,retain) id<SomeType> centerPhoto;
@property(nonatomic,retain) id<SomeType, SomeOtherType> centerPhoto;

-(TTThumbsViewController *) createThumbsViewController;
- (id<FooBar>)someMethodThatReturnsSomethingThatConformsToAProtocol;
- (void) appendObjects:(id) firstObject,...;
@end