[Variables]
CurrentStyle=f
Width=300

[measureStyle]
Measure=String
String=#CurrentStyle#
DynamicVariables=1
IfMatch=t
IfMatchAction=[!SetOption meterStyleSelectedHighlight X [meterShortTimeButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%#I:%M %p"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch2=T
IfMatchAction2=[!SetOption meterStyleSelectedHighlight X [meterLongTimeButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%#I:%M:%S %p"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch3=d
IfMatchAction3=[!SetOption meterStyleSelectedHighlight X [meterShortDateButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%m/%d/%Y"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch4=D
IfMatchAction4=[!SetOption meterStyleSelectedHighlight X [meterLongDateButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%B %#d, %G"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch5=f
IfMatchAction5=[!SetOption meterStyleSelectedHighlight X [meterShortDateTimeButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%B %#d, %G %#I:%M %p"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch6=F
IfMatchAction6=[!SetOption meterStyleSelectedHighlight X [meterLongDateTimeButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%A, %B %#d, %G %#I:%M %p"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch7=R
IfMatchAction7=[!SetOption meterStyleSelectedHighlight X [meterRelativeTimeButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption meterStyleDisplay Text "[measureTimeAgo][measureTimeLabel]"][!UpdateMeter meterStyleDisplay][!Redraw]

[measureTimeAgo]
Measure=Calc
Formula=0 < 60 ? 0 : (0 < 3600 ? Round(0 / 60) : (0 < 86400 ? Round(0 / 3600) : (0 < 2592000 ? Round(0 / 86400) : (0 < 31104000 ? Round(0 / 2592000) : Round(0 / 31104000)))))
IfCondition=0 = 1
IfTrueAction=[!SetOption measureTimeLabel String " second ago"]
IfCondition2=((0 <> 1) && (0 < 60))
IfTrueAction2=[!SetOption measureTimeLabel String " seconds ago"]
IfCondition3=((0 >= 60) && (0 < 90))
IfTrueAction3=[!SetOption measureTimeLabel String " minute ago"]
IfCondition4=((0 >= 90) && (0 < 3600))
IfTrueAction4=[!SetOption measureTimeLabel String " minutes ago"]
IfCondition5=((0 >= 3600) && (0 < 5400))
IfTrueAction5=[!SetOption measureTimeLabel String " hour ago"]
IfCondition6=((0 >= 5400) && (0 < 86400))
IfTrueAction6=[!SetOption measureTimeLabel String " hours ago"]
IfCondition7=((0 >= 86400) && (0 < 129600))
IfTrueAction7=[!SetOption measureTimeLabel String " day ago"]
IfCondition8=((0 >= 129600) && (0 < 2592000))
IfTrueAction8=[!SetOption measureTimeLabel String " days ago"]
IfCondition9=((0 >= 2592000) && (0 < 3888000))
IfTrueAction9=[!SetOption measureTimeLabel String " month ago"]
IfCondition10=((0 >= 3888000) && (0 < 31104000))
IfTrueAction10=[!SetOption measureTimeLabel String " months ago"]
IfCondition11=((0 >= 31104000) && (0 < 46656000))
IfTrueAction11=[!SetOption measureTimeLabel String " year ago"]
IfCondition12=((0 >= 46656000))
IfTrueAction12=[!SetOption measureTimeLabel String " years ago"]

[measureTimeLabel]
Measure=String

[measureStyleDisplay]
Measure=Time

[measureWindowsTime]
Measure=Time
TimeZone=0
DaylightSavingTime=0

[measureUnixTimeStart]
Measure=Time
TimeStamp=1970/01/01 00:00:00
TimeStampFormat=%Y/%m/%d %H:%M:%S
UpdateDivider=-1

[measureUnixTime]
Measure=Calc
Formula=MeasureWindowsTime-MeasureUnixTimeStart

[measureOffset]
Measure=Calc
UpdateDivider=-1

[measureTimeTarget]
Measure=Calc
Formula=MeasureUnixTime+MeasureOffset

[measureInput]
Measure=Plugin
Plugin=InputText
W=[meterTextBoxBackground:W]
H=[meterTextBoxBackground:H]
FontSize=20
FontFace=#FontFace#
AntiAlias=1
InputNumber=1
InputLimit=6
X=[meterTextBoxBackground:X]
Y=[meterTextBoxBackground:Y]
Command1=[!SetOption MeasureOffset Formula $UserInput$][!UpdateMeasure MeasureOffset][!UpdateMeasure MeasureTimeTarget][!SetClip <t:[measureTimeTarget]:#CurrentStyle#>]
Command2=[!SetOption MeasureOffset Formula $UserInput$*60][!UpdateMeasure MeasureOffset][!UpdateMeasure MeasureTimeTarget][!SetClip <t:[measureTimeTarget]:#CurrentStyle#>]
Command3=[!SetOption MeasureOffset Formula $UserInput$*60*60][!UpdateMeasure MeasureOffset][!UpdateMeasure MeasureTimeTarget][!SetClip <t:[measureTimeTarget]:#CurrentStyle#>]
Command4=[!SetOption MeasureOffset Formula $UserInput$*60*60*24][!UpdateMeasure MeasureOffset][!UpdateMeasure MeasureTimeTarget][!SetClip <t:[measureTimeTarget]:#CurrentStyle#>]
Group=TextGroup | TextBoxGroup

[measureTimeUnit]
Measure=String
String=Minutes
IfMatch=Seconds
IfMatchAction=[!SetOption meterTextBoxBackground LeftMouseUpAction """[!CommandMeasure measureInput "ExecuteBatch 1"]"""][!UpdateMeter meterTextBoxBackground]
IfMatch2=Minutes
IfMatchAction2=[!SetOption meterTextBoxBackground LeftMouseUpAction """[!CommandMeasure measureInput "ExecuteBatch 2"]"""][!UpdateMeter meterTextBoxBackground]
IfMatch3=Hours
IfMatchAction3=[!SetOption meterTextBoxBackground LeftMouseUpAction """[!CommandMeasure measureInput "ExecuteBatch 3"]"""][!UpdateMeter meterTextBoxBackground]
IfMatch4=Days
IfMatchAction4=[!SetOption meterTextBoxBackground LeftMouseUpAction """[!CommandMeasure measureInput "ExecuteBatch 4"]"""][!UpdateMeter meterTextBoxBackground]

[meterTimestampTitleBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterTimestampTitle:W],[meterTimestampTitle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=[meterEdge:H]
Hidden=1

[meterTimestampTitle]
Meter=String
Group=TextGroup | TimestampGroup
Text=Discord Timestamp Generator
AntiAlias=1
Padding=#PaddingSize#
Y=r
W=(#Width# - #SidePadding# * 2)
Hidden=1
FontSize=18
FontFace=#DisplayFont#

[meterStyleTitleBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterStyleTitle:W],[meterStyleTitle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=R
Hidden=1

[meterStyleTitle]
Meter=String
Group=TextGroup | TimestampGroup
Text=Style
AntiAlias=1
Padding=#PaddingSize#
Y=r
W=(#Width# - #SidePadding# * 2)
Hidden=1
FontFace=#FontFace#

[meterShortTimeButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterShortTimeButton:W],[meterShortTimeButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=R
Hidden=1

[meterShortTimeButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=t
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 14)
W=(#Width# / 7)
StringAlign=Center
Hidden=1
FontFace=#FontFace#
ToolTipText=Short Time
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle t][!UpdateMeasure measureStyle]

[meterLongTimeButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterLongTimeButton:W],[meterLongTimeButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 14)r
Hidden=1

[meterLongTimeButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=T
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 14)r
W=(#Width# / 7)
StringAlign=Center
Hidden=1
FontFace=#FontFace#
ToolTipText=Long Time
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle T][!UpdateMeasure measureStyle]

[meterShortDateButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterShortDateButton:W],[meterShortDateButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 14)r
Hidden=1

[meterShortDateButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=d
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 14)r
W=(#Width# / 7)
StringAlign=Center
Hidden=1
FontFace=#FontFace#
ToolTipText=Short Date
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle d][!UpdateMeasure measureStyle]

[meterLongDateButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterLongDateButton:W],[meterLongDateButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 14)r
Hidden=1

[meterLongDateButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=D
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 14)r
W=(#Width# / 7)
StringAlign=Center
Hidden=1
FontFace=#FontFace#
ToolTipText=Long Date
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle D][!UpdateMeasure measureStyle]

[meterShortDateTimeButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterShortDateTimeButton:W],[meterShortDateTimeButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 14)r
Hidden=1

[meterShortDateTimeButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=f
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 14)r
W=(#Width# / 7)
StringAlign=Center
Hidden=1
FontFace=#FontFace#
ToolTipText=Short Date/Time
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle f][!UpdateMeasure measureStyle]

[meterLongDateTimeButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterLongDateTimeButton:W],[meterLongDateTimeButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 14)r
Hidden=1

[meterLongDateTimeButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=F
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 14)r
W=(#Width# / 7)
StringAlign=Center
Hidden=1
FontFace=#FontFace#
ToolTipText=Long Date/Time
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle F][!UpdateMeasure measureStyle]

[meterRelativeTimeButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterRelativeTimeButton:W],[meterRelativeTimeButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 14)r
Hidden=1

[meterRelativeTimeButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=R
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 14)r
W=(#Width# / 7)
StringAlign=Center
Hidden=1
FontFace=#FontFace#
ToolTipText=Relative Time
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle R][!UpdateMeasure measureStyle]

[meterStyleSelectedHighlight]
Meter=Shape
Shape=Rectangle 0,0,(#Width# / 7),[meterRelativeTimeButton:H], #CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color #LightHighlight#,#NoGradientTransparency#
DynamicVariables=1
Y=r
Group=TimestampGroup
Hidden=1

[meterTimeUnitTitleBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterTimeUnitTitle:W],[meterTimeUnitTitle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=#SidePadding#R
Hidden=1

[meterTimeUnitTitle]
Meter=String
Group=TextGroup | TimestampGroup
Text=Add time in:
AntiAlias=1
Padding=#PaddingSize#
Y=r
W=(#Width# - #SidePadding# * 2)
Hidden=1
FontFace=#FontFace#

[meterSecButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterSecButton:W],[meterSecButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=R
Hidden=1

[meterSecButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=Seconds
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 8)
W=(#Width# / 4)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTimeUnit String "Seconds"][!UpdateMeasure measureTimeUnit][!UpdateMeter meterSelectedUnit][!UpdateMeter meterSelectedUnitBackground][!Redraw]
Hidden=1
FontFace=#FontFace#

[measureMinButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[measureMinButton:W],[measureMinButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 8)r
Hidden=1

[measureMinButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=Minutes
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 8)r
W=(#Width# / 4)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTimeUnit String "Minutes"][!UpdateMeasure measureTimeUnit][!UpdateMeter meterSelectedUnit][!UpdateMeter meterSelectedUnitBackground][!Redraw]
Hidden=1
FontFace=#FontFace#

[meterHrButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterHrButton:W],[meterHrButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 8)r
Hidden=1

[meterHrButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=Hours
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 8)r
W=(#Width# / 4)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTimeUnit String "Hours"][!UpdateMeasure measureTimeUnit][!UpdateMeter meterSelectedUnit][!UpdateMeter meterSelectedUnitBackground][!Redraw]
Hidden=1
FontFace=#FontFace#

[meterDayButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterDayButton:W],[meterDayButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 8)r
Hidden=1

[meterDayButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=Days
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 8)r
W=(#Width# / 4)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTimeUnit String "Days"][!UpdateMeasure measureTimeUnit][!UpdateMeter meterSelectedUnit][!UpdateMeter meterSelectedUnitBackground][!Redraw]
Hidden=1
FontFace=#FontFace#

[meterDivider]
Meter=Image
Group=TimestampGroup
Y=R
H=10
Hidden=1

[meterTextBoxBackground]
Meter=Shape
Shape=Rectangle 0,0,(#Width# / 4),37,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=R
X=(#Width# / 4)
Hidden=1

[meterSelectedUnitBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterSelectedUnit:W],[meterSelectedUnit:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=r
X=R
Hidden=1

[meterSelectedUnit]
Meter=String
Group=TextGroup | TimestampGroup
MeasureName=measureTimeUnit
AntiAlias=1
Padding=#PaddingSize#
Y=r
X=r
Hidden=1
FontFace=#FontFace#

[meterStyleDisplayBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterStyleDisplay:W],[meterStyleDisplay:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=#SidePadding#R
X=[meterStyleDisplay:X]
Hidden=1

[meterStyleDisplay]
Meter=String
MeasureName=measureStyleDisplay
Y=r
Group=TextGroup | TimestampGroup
Hidden=1
AntiAlias=1
StringAlign=Center
X=(#Width# / 2)
Padding=#PaddingSize#
OnUpdateAction=[!UpdateMeter meterStyleDisplayBackground]
