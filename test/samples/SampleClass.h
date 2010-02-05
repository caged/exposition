@protocol FooBar

@end

@interface SampleClass : NSObject
{
    
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