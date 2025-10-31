[Variables]
CurrentStyle=f
Width=300
ShortTimeText=Short Time
LongTimeText=Long Time
ShortDateText=Short Date
LongDateText=Long Date
ShortDateTimeText=Short Date/Time
LongDateTimeText=Long Date/Time
RelativeTimeText=Relative Time

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
IfMatchAction4=[!SetOption meterStyleSelectedHighlight X [meterLongDateButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%B %#d, %Y"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch5=f
IfMatchAction5=[!SetOption meterStyleSelectedHighlight X [meterShortDateTimeButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%B %#d, %Y %#I:%M %p"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch6=F
IfMatchAction6=[!SetOption meterStyleSelectedHighlight X [meterLongDateTimeButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption measureStyleDisplay Format "%A, %B %#d, %Y %#I:%M %p"][!UpdateMeasure measureStyleDisplay][!SetOption meterStyleDisplay Text ""][!UpdateMeter meterStyleDisplay][!Redraw]
IfMatch7=R
IfMatchAction7=[!SetOption meterStyleSelectedHighlight X [meterRelativeTimeButton:X]][!UpdateMeter meterStyleSelectedHighlight][!SetOption meterStyleDisplay Text "%4%2%3%5"][!UpdateMeter meterStyleDisplay][!Redraw]

[measureRelativeTime]
Measure=Calc
DynamicVariables=1
Formula=[measureDifferenceAbs] < 60 ? [measureDifferenceAbs] : ([measureDifferenceAbs] < 3600 ? Round([measureDifferenceAbs] / 60) : ([measureDifferenceAbs] < 86400 ? Round([measureDifferenceAbs] / 3600) : ([measureDifferenceAbs] < 2592000 ? Round([measureDifferenceAbs] / 86400) : ([measureDifferenceAbs] < 31104000 ? Round([measureDifferenceAbs] / 2592000) : Round([measureDifferenceAbs] / 31104000)))))
IfCondition=[measureDifferenceAbs] = 1
IfTrueAction=[!SetOption measureTimeLabel String " second"]
IfCondition2=(([measureDifferenceAbs] <> 1) && ([measureDifferenceAbs] < 60))
IfTrueAction2=[!SetOption measureTimeLabel String " seconds"]
IfCondition3=(([measureDifferenceAbs] >= 60) && ([measureDifferenceAbs] < 90))
IfTrueAction3=[!SetOption measureTimeLabel String " minute"]
IfCondition4=(([measureDifferenceAbs] >= 90) && ([measureDifferenceAbs] < 3600))
IfTrueAction4=[!SetOption measureTimeLabel String " minutes"]
IfCondition5=(([measureDifferenceAbs] >= 3600) && ([measureDifferenceAbs] < 5400))
IfTrueAction5=[!SetOption measureTimeLabel String " hour"]
IfCondition6=(([measureDifferenceAbs] >= 5400) && ([measureDifferenceAbs] < 86400))
IfTrueAction6=[!SetOption measureTimeLabel String " hours"]
IfCondition7=(([measureDifferenceAbs] >= 86400) && ([measureDifferenceAbs] < 129600))
IfTrueAction7=[!SetOption measureTimeLabel String " day"]
IfCondition8=(([measureDifferenceAbs] >= 129600) && ([measureDifferenceAbs] < 2592000))
IfTrueAction8=[!SetOption measureTimeLabel String " days"]
IfCondition9=(([measureDifferenceAbs] >= 2592000) && ([measureDifferenceAbs] < 3888000))
IfTrueAction9=[!SetOption measureTimeLabel String " month"]
IfCondition10=(([measureDifferenceAbs] >= 3888000) && ([measureDifferenceAbs] < 31104000))
IfTrueAction10=[!SetOption measureTimeLabel String " months"]
IfCondition11=(([measureDifferenceAbs] >= 31104000) && ([measureDifferenceAbs] < 46656000))
IfTrueAction11=[!SetOption measureTimeLabel String " year"]
IfCondition12=(([measureDifferenceAbs] >= 46656000))
IfTrueAction12=[!SetOption measureTimeLabel String " years"]
IfCondition13=[measureDifference] < 0
IfTrueAction13=[!SetOption measurePrefix String ""][!SetOption measureSuffix String " ago"]
IfCondition14=[measureDifference] >= 0
IfTrueAction14=[!SetOption measurePrefix String "in "][!SetOption measureSuffix String ""]
OnUpdateAction=[!UpdateMeasure measureTimeLabel][!UpdateMeasure measurePrefix][!UpdateMeasure measureSuffix]

[measureTimeLabel]
Measure=String
UpdateDivider=-1

[measurePrefix]
Measure=String
UpdateDivider=-1

[measureSuffix]
Measure=String
UpdateDivider=-1

[measureStyleDisplay]
Measure=Time
TimeStamp=[measureDisplayTimeTarget]
DynamicVariables=1

[measureWindowsTime]
Measure=Time

[measureWindowsUtcTime]
Measure=Time
TimeZone=0
DaylightSavingTime=0

[measureTimeZoneOffset]
Measure=Calc
Formula=measureWindowsTime-measureWindowsUtcTime

[measureUnixTimeStart]
Measure=Time
TimeStamp=1970/01/01 00:00:00
TimeStampFormat=%Y/%m/%d %H:%M:%S
UpdateDivider=-1

[measureUnixTime]
Measure=Calc
Formula=measureWindowsUtcTime-MeasureUnixTimeStart

[measureTimeTarget]
Measure=Calc
Formula=measureTargetDate-MeasureUnixTimeStart-measureTimeZoneOffset
UpdateDivider=-1

[measureDifference]
Measure=Calc
Formula=measureTargetDate-measureWindowsTime
OnUpdateAction=[!UpdateMeasure measureDifferenceAbs]
UpdateDivider=-1

[measureDifferenceAbs]
Measure=Calc
Formula=Abs(measureDifference)
OnUpdateAction=[!UpdateMeasure measureRelativeTime]
UpdateDivider=-1

[measureDisplayTimeTarget]
Measure=Calc
Formula=measureTargetDate
OnUpdateAction=[!UpdateMeasure measureStyleDisplay]
UpdateDivider=-1

[measureMonth]
Measure=Time
Format=%#m

[measureDay]
Measure=Time
Format=%#d

[measureYear]
Measure=Time
Format=%Y

[measureTargetMonth]
Measure=Calc
DynamicVariables=1
Formula=[measureMonth]
OnUpdateAction=[!UpdateMeasure measureLastDay]

[measureTargetDay]
Measure=Calc
DynamicVariables=1
Formula=[measureDay]
OnUpdateAction=[!UpdateMeter meterDayDateButton]

[measureLastDay]
Measure=Calc
IfCondition=([measureTargetMonth] = 1) || ([measureTargetMonth] = 3) || ([measureTargetMonth] = 5) || ([measureTargetMonth] = 6) || ([measureTargetMonth] = 8) || ([measureTargetMonth] = 10) || ([measureTargetMonth] = 12)
IfTrueAction=[!SetOption #CURRENTSECTION# Formula 31][!UpdateMeasure #CURRENTSECTION#]
IfCondition2=([measureTargetMonth] = 4) || ([measureTargetMonth] = 7) || ([measureTargetMonth] = 9) || ([measureTargetMonth] = 11)
IfTrueAction2=[!SetOption #CURRENTSECTION# Formula 30][!UpdateMeasure #CURRENTSECTION#]
IfCondition3=([measureTargetMonth] = 2) && ([measureTargetYear] % 4 <> 0)
IfTrueAction3=[!SetOption #CURRENTSECTION# Formula 28][!UpdateMeasure #CURRENTSECTION#]
IfCondition4=([measureTargetMonth] = 2) && ([measureTargetYear] % 4 = 0)
IfTrueAction4=[!SetOption #CURRENTSECTION# Formula 29][!UpdateMeasure #CURRENTSECTION#]
DynamicVariables=1
OnChangeAction=[!SetOption measureTargetDay Formula "Min([measureTargetDay], [measureLastDay])"][!UpdateMeasure measureTargetDay]

[measureTargetYear]
Measure=Calc
DynamicVariables=1
Formula=[measureYear]
OnUpdateAction=[!UpdateMeasure measureLastDay]

[measureTargetHour]
Measure=Calc
DynamicVariables=1
Formula=[measureHours]

[measureTargetMinute]
Measure=Calc
DynamicVariables=1
Formula=[measureMinutes]
OnChangeAction=[!UpdateMeasure measureTargetMinuteString]

[measureTargetMinuteString]
Measure=String
DynamicVariables=1
String=[measureTargetMinute]
RegExpSubstitute=1
Substitute="(\b\d\b)":"0\1"

[measureTargetDate]
Measure=Time
DynamicVariables=1
TimeStamp=[measureTargetMonth]/[measureTargetDay]/[measureTargetYear] [measureTargetHour]:[measureTargetMinute]
TimeStampFormat=%#m/%#d/%Y %H:%M
OnUpdateAction=[!UpdateMeasure measureDisplayTimeTarget][!UpdateMeasure measureTimeTarget][!UpdateMeasure measureDifference]

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

[meterStyleName]
Meter=String
Group=TextGroup | TimestampGroup
Text=#ShortDateTimeText#
AntiAlias=1
Padding=#PaddingSize#
Y=r
X=R
Hidden=1
FontFace=#FontFace#
StringAlign=Right

[timeButtonStyle]
Group=TextGroup | TimestampGroup
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 14)r
W=(#Width# / 7)
StringAlign=Center
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
MeterStyle=timeButtonStyle
Text=t
X=(#Width# / 14)
ToolTipText=#ShortTimeText#
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle t][!UpdateMeasure measureStyle][!SetOption meterStyleName Text "#ShortTimeText#"][!UpdateMeter meterStyleName][!Redraw]

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
MeterStyle=timeButtonStyle
Text=T
ToolTipText=#LongTimeText#
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle T][!UpdateMeasure measureStyle][!SetOption meterStyleName Text "#LongTimeText#"][!UpdateMeter meterStyleName][!Redraw]

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
MeterStyle=timeButtonStyle
Text=d
ToolTipText=#ShortDateText#
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle d][!UpdateMeasure measureStyle][!SetOption meterStyleName Text "#ShortDateText#"][!UpdateMeter meterStyleName][!Redraw]

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
MeterStyle=timeButtonStyle
Text=D
ToolTipText=#LongDateText#
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle D][!UpdateMeasure measureStyle][!SetOption meterStyleName Text "#LongDateText#"][!UpdateMeter meterStyleName][!Redraw]

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
MeterStyle=timeButtonStyle
Text=f
ToolTipText=#ShortDateTimeText#
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle f][!UpdateMeasure measureStyle][!SetOption meterStyleName Text "#ShortDateTimeText#"][!UpdateMeter meterStyleName][!Redraw]

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
MeterStyle=timeButtonStyle
Text=F
ToolTipText=#LongDateTimeText#
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle F][!UpdateMeasure measureStyle][!SetOption meterStyleName Text "#LongDateTimeText#"][!UpdateMeter meterStyleName][!Redraw]

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
MeterStyle=timeButtonStyle
Text=R
ToolTipText=#RelativeTimeText#
LeftMouseUpAction=#PlayButtonClick#[!SetVariable CurrentStyle R][!UpdateMeasure measureStyle][!SetOption meterStyleName Text "#RelativeTimeText#"][!UpdateMeter meterStyleName][!Redraw]

[meterStyleSelectedHighlight]
Meter=Shape
Shape=Rectangle (#Width# / 28),(2 * [meterRelativeTimeButton:H] / 3),(#Width# / 14), 4, 2 | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color #LightHighlight#,#NoGradientTransparency#
DynamicVariables=1
Y=r
Group=TimestampGroup
Hidden=1

[meterTimeUnitDivider]
Meter=Image
Group=TimestampGroup
Y=R
H=#SidePadding#
Hidden=1

[meterDateTitleBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterDateTimeUnitTitle:W],[meterDateTimeUnitTitle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=R
Hidden=1

[meterDateTimeUnitTitle]
Meter=String
Group=TextGroup | TimestampGroup
Text=Specific date:
AntiAlias=1
Padding=#PaddingSize#
Y=r
W=(#Width# - #SidePadding# * 2)
Hidden=1
FontFace=#FontFace#

[meterMonthButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterMonthButton:W],[meterMonthButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=R
Hidden=1

[meterMonthButton]
Meter=String
Group=TextGroup | TimestampGroup
DynamicVariables=1
Text=[measureTargetMonth]
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 6)
W=(#Width# / 3)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTargetMonth Formula "(([measureTargetMonth] + 1) + 11) % 12 + 1"][!UpdateMeasure measureTargetMonth][!UpdateMeter meterMonthButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollUpAction=#PlayButtonClick#[!SetOption measureTargetMonth Formula "(([measureTargetMonth] + 1) + 11) % 12 + 1"][!UpdateMeasure measureTargetMonth][!UpdateMeter meterMonthButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
RightMouseUpAction=#PlayButtonClick#[!SetOption measureTargetMonth Formula "(([measureTargetMonth] - 1) + 11) % 12 + 1"][!UpdateMeasure measureTargetMonth][!UpdateMeter meterMonthButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollDownAction=#PlayButtonClick#[!SetOption measureTargetMonth Formula "(([measureTargetMonth] - 1) + 11) % 12 + 1"][!UpdateMeasure measureTargetMonth][!UpdateMeter meterMonthButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
Hidden=1
FontFace=#FontFace#

[meterDayDateButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterDayDateButton:W],[meterDayDateButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 6)r
Hidden=1

[meterDayDateButton]
Meter=String
Group=TextGroup | TimestampGroup
DynamicVariables=1
Text=[measureTargetDay]
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 6)r
W=(#Width# / 3)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTargetDay Formula "(([measureTargetDay] + 1) + [measureLastDay] - 1) % [measureLastDay] + 1"][!UpdateMeasure measureTargetDay][!UpdateMeter meterDayDateButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollUpAction=#PlayButtonClick#[!SetOption measureTargetDay Formula "(([measureTargetDay] + 1) + [measureLastDay] - 1) % [measureLastDay] + 1"][!UpdateMeasure measureTargetDay][!UpdateMeter meterDayDateButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
RightMouseUpAction=#PlayButtonClick#[!SetOption measureTargetDay Formula "(([measureTargetDay] - 1) + [measureLastDay] - 1) % [measureLastDay] + 1"][!UpdateMeasure measureTargetDay][!UpdateMeter meterDayDateButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollDownAction=#PlayButtonClick#[!SetOption measureTargetDay Formula "(([measureTargetDay] - 1) + [measureLastDay] - 1) % [measureLastDay] + 1"][!UpdateMeasure measureTargetDay][!UpdateMeter meterDayDateButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
Hidden=1
FontFace=#FontFace#

[meterYearButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterYearButton:W],[meterYearButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 6)r
Hidden=1

[meterYearButton]
Meter=String
Group=TextGroup | TimestampGroup
DynamicVariables=1
Text=[measureTargetYear]
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 6)r
W=(#Width# / 3)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTargetYear Formula "[measureTargetYear] + 1"][!UpdateMeasure measureTargetYear][!UpdateMeter meterYearButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollUpAction=#PlayButtonClick#[!SetOption measureTargetYear Formula "[measureTargetYear] + 1"][!UpdateMeasure measureTargetYear][!UpdateMeter meterYearButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
RightMouseUpAction=#PlayButtonClick#[!SetOption measureTargetYear Formula "[measureTargetYear] - 1"][!UpdateMeasure measureTargetYear][!UpdateMeter meterYearButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollDownAction=#PlayButtonClick#[!SetOption measureTargetYear Formula "[measureTargetYear] - 1"][!UpdateMeasure measureTargetYear][!UpdateMeter meterYearButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
Hidden=1
FontFace=#FontFace#

[meterTimeDivider]
Meter=Image
Group=TimestampGroup
Y=R
H=#SidePadding#
Hidden=1

[meterHourButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterHourButton:W],[meterHourButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=R
X=(#Width# / 4)
Hidden=1

[meterHourButton]
Meter=String
Group=TextGroup | TimestampGroup
DynamicVariables=1
Text=[measureTargetHour]
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 12)r
W=(#Width# / 6)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTargetHour Formula "(([measureTargetHour] + 1) % 24 + 24) % 24"][!UpdateMeasure measureTargetHour][!UpdateMeter meterHourButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollUpAction=#PlayButtonClick#[!SetOption measureTargetHour Formula "(([measureTargetHour] + 1) % 24 + 24) % 24"][!UpdateMeasure measureTargetHour][!UpdateMeter meterHourButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
RightMouseUpAction=#PlayButtonClick#[!SetOption measureTargetHour Formula "(([measureTargetHour] - 1) % 24 + 24) % 24"][!UpdateMeasure measureTargetHour][!UpdateMeter meterHourButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollDownAction=#PlayButtonClick#[!SetOption measureTargetHour Formula "(([measureTargetHour] - 1) % 24 + 24) % 24"][!UpdateMeasure measureTargetHour][!UpdateMeter meterHourButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
Hidden=1
FontFace=#FontFace#

[meterColonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterColon:W],[meterColon:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 8)r
Hidden=1

[meterColon]
Meter=String
Group=TextGroup | TimestampGroup
DynamicVariables=1
Text=:
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 24)r
W=(#Width# / 12)
StringAlign=Center
Hidden=1
FontFace=#FontFace#

[meterMinuteButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterMinuteButton:W],[meterMinuteButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=r
X=(#Width# / 12)r
Hidden=1

[meterMinuteButton]
Meter=String
Group=TextGroup | TimestampGroup
DynamicVariables=1
Text=[measureTargetMinuteString]
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 12)r
W=(#Width# / 6)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!SetOption measureTargetMinute Formula "(([measureTargetMinute] + 1) % 60 + 60) % 60"][!UpdateMeasure measureTargetMinute][!UpdateMeter meterMinuteButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollUpAction=#PlayButtonClick#[!SetOption measureTargetMinute Formula "(([measureTargetMinute] + 1) % 60 + 60) % 60"][!UpdateMeasure measureTargetMinute][!UpdateMeter meterMinuteButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
RightMouseUpAction=#PlayButtonClick#[!SetOption measureTargetMinute Formula "(([measureTargetMinute] - 1) % 60 + 60) % 60"][!UpdateMeasure measureTargetMinute][!UpdateMeter meterMinuteButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
MouseScrollDownAction=#PlayButtonClick#[!SetOption measureTargetMinute Formula "(([measureTargetMinute] - 1) % 60 + 60) % 60"][!UpdateMeasure measureTargetMinute][!UpdateMeter meterMinuteButton][!UpdateMeasure measureTargetDate][!UpdateMeasure measureTimeTarget][!UpdateMeasure MeasureDisplayTimeTarget][!UpdateMeter meterStyleDisplay][!Redraw]
Hidden=1
FontFace=#FontFace#

[meterStyleDisplayDivider]
Meter=Image
Group=TimestampGroup
Y=R
H=#SidePadding#
Hidden=1

[meterStyleDisplayBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterStyleDisplay:W],[meterStyleDisplay:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=R
X=[meterStyleDisplay:X]
Hidden=1

[meterStyleDisplay]
Meter=String
MeasureName=measureStyleDisplay
MeasureName2=measureRelativeTime
MeasureName3=measureTimeLabel
MeasureName4=measurePrefix
MeasureName5=measureSuffix
Y=r
Group=TextGroup | TimestampGroup
Hidden=1
AntiAlias=1
StringAlign=Center
X=(#Width# / 2)
Padding=#PaddingSize#
OnUpdateAction=[!UpdateMeter meterStyleDisplayBackground]
LeftMouseUpAction=#PlayButtonClick#[!SetClip <t:[measureTimeTarget]:#CurrentStyle#>][!SetOption meterStyleDisplay ToolTipText "Copied to clipboard!"]
MouseLeaveAction=[!SetOption meterStyleDisplay ToolTipText "Click to copy to clipboard"]
ToolTipText=Click to copy to clipboard
