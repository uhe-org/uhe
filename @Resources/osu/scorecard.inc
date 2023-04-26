[Rainmeter]
AccurateText=1
DynamicWindowSize=1
@Include=#@#Variables/mainvariables.inc
@Include2=#@#Variables/osuvariables.inc
ContextTitle2="Edit base scorecard"
ContextAction2=["#@#osu/scorecard.inc"]
Group=osu | osuScore | AllSkins

[Variables]
Width=400
DropdownHeight=600
BeatmapImageWidth=75
Say=[!CommandMeasure SpeechHost "[measure100] 100s [measureMiss] miss and worth [measurePPSpeech]"]
ShowExtendedStatsOnStart=1
OnConnectErrorTriggered=0
OnRegExpErrorTriggered=0
UserCollapsed=0
volume-xmark=[\xf6a9]
volume-high=[xf028]
BaseFinishAction=[!ShowMeterGroup Content][!EnableMeasureGroup TimeMeasures][!HideMeterGroup LoadingGroup][!EnableMeasure measureOnConnectError][!UpdateMeasure measureOnConnectError][!DisableMeasure measureOnConnectError][!SetVariable OnRegExpErrorTriggered 0]
BaseOnConnectErrorAction=[!HideMeterGroup Content][!DisableMeasureGroup TimeMeasures][!HideMeterGroup UpArrowGroup][!HideMeterGroup DownArrowGroup][!ShowMeterGroup LoadingGroup][!SetOption meterLoading Text "No internet connection..."][!UpdateMeter meterLoading][!SetVariable OnConnectErrorTriggered 1][!HideMeter meterDropdown][!HideMeter meterDropdownBackground][!Redraw]
BaseOnRegExpErrorAction=[!HideMeterGroup Content][!DisableMeasureGroup TimeMeasures][!HideMeterGroup UpArrowGroup][!HideMeterGroup DownArrowGroup][!ShowMeterGroup LoadingGroup][!SetOption meterLoading Text "No recent score..."][!UpdateMeter meterLoading][!HideMeter meterLoadingSpinner][!HideMeter meterSpinnerBackground][!SetVariable OnRegExpErrorTriggered 1][!HideMeter meterDropdown][!HideMeter meterDropdownBackground][!Redraw]
BaseScoreChangeAction=[!HideMeter meterDropdown][!HideMeter meterDropdownBackground][!SetOption measureMultiplier Formula 0][!UpdateMeasure measureMultiplier][!SetVariable Size 0][!SetOption meterDropdown H 0][!HideMeterGroup UpArrowGroup][!HideMeterGroup DownArrowGroup][!CommandMeasure measureOsuFile Run][!EnableMeasure measureSpeech][!UpdateMeasure measureSpeech][!DisableMeasure measureSpeech]
AccuracyRegExp=.*"accuracy":(.*),
ModsRegExp=.*"mods":\[(.*)\],
ScoreRegExp=.*"score":(.*),
MaxComboRegExp=.*"max_combo":(.*),
Count50RegExp=.*"count_50":(.*),
Count100RegExp=.*"count_100":(.*),
Count300RegExp=.*"count_300":(.*),
CountMissRegExp=.*"count_miss":(.*)},
RankRegExp=.*"rank":"(.*)",
CreatedAtRegExp=.*"created_at":"(.*)",
BestIDRegExp=.*"best_id":(.*),
PPRegExp=.*"pp":(.*),

[measureSpeech]
Measure=Calc
Disabled=1
IfCondition=measureMuted = 0
IfTrueAction=#Say#

[measureOsuFile]
Measure=Plugin
Plugin=RunCommand
DynamicVariables=1
Parameter=curl "https://osu.ppy.sh/osu/[&measureID]" --output beatmap.osu
FinishAction=[!CommandMeasure measureExtendedStats Run]
OutputType=UTF8

[measureExtendedStats]
Measure=Plugin
Plugin=RunCommand
DynamicVariables=1
Parameter=dotnet run --project [measureDocsFolder]\GitHub\osu-tools\PerformanceCalculator -- simulate [measurePerfCalcMode] beatmap.osu [measurePerfCalcMods]
OutputType=UTF8
FinishAction=[!EnableMeasure measureShowExtendedStatsOnStart][!UpdateMeasure measureShowExtendedStatsOnStart][!DisableMeasure measureShowExtendedStatsOnStart]

[measurePerfCalcMode]
Measure=String
String=#Mode#
Substitute="fruits":"catch"

[measurePerfCalcMods]
Measure=WebParser
URL=[measureData]
StringIndex=5
RegExpSubstitute=1
Substitute='"':"", ",":"", "(..)":"-m \1 "

[measureShowExtendedStatsOnStart]
Measure=Calc
Formula=#ShowExtendedStatsOnStart#
Disabled=1
DynamicVariables=1
IfCondition=((measureShowExtendedStatsOnStart = 1) && (#UserCollapsed# = 0) && (#OnConnectErrorTriggered# = 0) && (#OnRegExpErrorTriggered# = 0))
IfTrueAction=#VerticalExpandCommand#
IfFalseAction=[!ShowMeterGroup DownArrowGroup][!SetOption measureMultiplier Formula 0][!UpdateMeasure measureMultiplier][!SetVariable Size 0][!SetOption meterDropdown H 0]

[SpeechHost]
Measure=Plugin
Plugin=Speech
Name=Microsoft Zira Desktop

[measureData]
Measure=WebParser
Header=Authorization: Bearer %UheOsuToken%
UpdateRate=5
RegExp=(?siU)#AccuracyRegExp##BestIDRegExp##CreatedAtRegExp##MaxComboRegExp##ModsRegExp##PPRegExp##RankRegExp##ScoreRegExp##Count100RegExp##Count300RegExp##Count50RegExp##CountMissRegExp#.*"beatmapset_id":(.*),.*"id":(.*),.*"version":"(.*)",.*"title":"(.*)",
FinishAction=#BaseFinishAction#
OnConnectErrorAction=#BaseOnConnectErrorAction#
OnRegExpErrorAction=#BaseOnRegExpErrorAction#

[measureOnConnectError]
Measure=Calc
DynamicVariables=1
Formula=#OnConnectErrorTriggered#
Disabled=1
IfCondition=measureOnConnectError = 1
IfTrueAction=[!EnableMeasure measureShowExtendedStatsOnStart][!UpdateMeasure measureShowExtendedStatsOnStart][!DisableMeasure measureShowExtendedStatsOnStart][!SetVariable OnConnectErrorTriggered 0]

[measureStateAnimation]
ActionList1=ShowCollapseButton | #BaseVerticalExpand#
ActionList2=ShowExpandButton | #BaseVerticalCollapse#
ShowCollapseButton=[!HideMeterGroup DownArrowGroup][!ShowMeterGroup UpArrowGroup][!Redraw]
ShowExpandButton=[!HideMeterGroup UpArrowGroup][!ShowMeterGroup DownArrowGroup][!Redraw]

[measureAccuracyString]
Measure=WebParser
URL=[measureData]
StringIndex=1

[measureAccuracyCalc]
Measure=Calc
Formula=Round(measureAccuracyString * 100, 2)

[measureAccuracy]
Measure=String
String=[measureAccuracyCalc]
DynamicVariables=1
RegExpSubstitute=1
Substitute='(.+)':"\1%"

[measureScore]
Measure=WebParser
URL=[measureData]
StringIndex=8
RegExpSubstitute=1
Substitute=#FormatNumberWithCommas#

[measureMaxCombo]
Measure=WebParser
URL=[measureData]
StringIndex=4
RegExpSubstitute=1
Substitute='(.+)':"\1x"

[measure300]
Measure=WebParser
URL=[measureData]
StringIndex=10

[measure100]
Measure=WebParser
URL=[measureData]
StringIndex=9

[measure50]
Measure=WebParser
URL=[measureData]
StringIndex=11

[measureMiss]
Measure=WebParser
URL=[measureData]
StringIndex=12

[measureMods]
Measure=WebParser
URL=[measureData]
StringIndex=5
RegExpSubstitute=1
Substitute='(.+)':"+\1", '"':"", ",":""

[measureRank]
Measure=WebParser
URL=[measureData]
StringIndex=7
Substitute="F":"D"
IfMatch=X|S
IfMatchAction=[!SetOption meterRank FontColor 255,255,0]
IfMatch2=XH|SH
IfMatchAction2=[!SetOption meterRank FontColor 128,128,128]
IfMatch3=A
IfMatchAction3=[!SetOption meterRank FontColor 3,192,60]
IfMatch4=B|C|D|F
IfMatchAction4=[!SetOption meterRank FontColor 194,59,34]

[measureRankDisplay]
Measure=String
DynamicVariables=1
String=[measureRank]
Substitute="SSH":"SS", "SH":"S"

[measureScoreBestID]
Measure=WebParser
URL=[measureData]
StringIndex=2
Substitute="null":"-1"

[measurePPString]
Measure=WebParser
URL=[measureData]
StringIndex=6

[measurePPCalc]
Measure=Calc
Formula=Round(measurePPString)

[measurePPSpeech]
Measure=String
String=[measurePPCalc]
DynamicVariables=1
RegExpSubstitute=1
Substitute='(.+)':"\1 pp", "null":"no pp"

[measurePP]
Measure=String
String=[measurePPCalc]
DynamicVariables=1
RegExpSubstitute=1
Substitute='(.+)':"\1pp", "null":"0pp"

[measureTitle]
Measure=WebParser
URL=[measureData]
StringIndex=16
RegExpSubstitute=1
Substitute='(.+)':"\1 ", "\\":""

[measureScoreDateString]
Measure=WebParser
URL=[measureData]
StringIndex=3
OnChangeAction=#BaseScoreChangeAction#
;find way of animating without duplicating code to hide expand/collapse buttons
;OnChangeAction=#VerticalCollapseCommand#[!CommandMeasure measureOsuFile Run][!EnableMeasure measureSpeech][!UpdateMeasure measureSpeech][!DisableMeasure measureSpeech]

[measureCurrentTime]
Measure=Time
TimeZone=0
DaylightSavingTime=0

[measureScoreDate]
Measure=Time
TimeStamp=[measureScoreDateString]
TimeStampFormat=%Y-%m-%dT%H:%M:%S
DynamicVariables=1
Group=TimeMeasures
Disabled=1

[measureTimeDiff]
Measure=Calc
Formula=(measureCurrentTime - measureScoreDate)

[measureTimeAgo]
Measure=Calc
Formula=measureTimeDiff < 60 ? measureTimeDiff : (measureTimeDiff < 3600 ? Round(measureTimeDiff / 60) : (measureTimeDiff < 86400 ? Round(measureTimeDiff / 3600) : (measureTimeDiff < 2592000 ? Round(measureTimeDiff / 86400) : (measureTimeDiff < 31104000 ? Round(measureTimeDiff / 2592000) : Round(measureTimeDiff / 31104000)))))
IfCondition=measureTimeDiff = 1
IfTrueAction=[!SetOption measureTimeLabel String " second ago"]
IfCondition2=((measureTimeDiff <> 1) && (measureTimeDiff < 60))
IfTrueAction2=[!SetOption measureTimeLabel String " seconds ago"]
IfCondition3=((measureTimeDiff >= 60) && (measureTimeDiff < 90))
IfTrueAction3=[!SetOption measureTimeLabel String " minute ago"]
IfCondition4=((measureTimeDiff >= 90) && (measureTimeDiff < 3600))
IfTrueAction4=[!SetOption measureTimeLabel String " minutes ago"]
IfCondition5=((measureTimeDiff >= 3600) && (measureTimeDiff < 5400))
IfTrueAction5=[!SetOption measureTimeLabel String " hour ago"]
IfCondition6=((measureTimeDiff >= 5400) && (measureTimeDiff < 86400))
IfTrueAction6=[!SetOption measureTimeLabel String " hours ago"]
IfCondition7=((measureTimeDiff >= 86400) && (measureTimeDiff < 129600))
IfTrueAction7=[!SetOption measureTimeLabel String " day ago"]
IfCondition8=((measureTimeDiff >= 129600) && (measureTimeDiff < 2592000))
IfTrueAction8=[!SetOption measureTimeLabel String " days ago"]
IfCondition9=((measureTimeDiff >= 2592000) && (measureTimeDiff < 3888000))
IfTrueAction9=[!SetOption measureTimeLabel String " month ago"]
IfCondition10=((measureTimeDiff >= 3888000) && (measureTimeDiff < 31104000))
IfTrueAction10=[!SetOption measureTimeLabel String " months ago"]
IfCondition11=((measureTimeDiff >= 31104000) && (measureTimeDiff < 46656000))
IfTrueAction11=[!SetOption measureTimeLabel String " year ago"]
IfCondition12=((measureTimeDiff >= 46656000))
IfTrueAction12=[!SetOption measureTimeLabel String " years ago"]
Disabled=1
Group=TimeMeasures

[measureTimeLabel]
Measure=String

[measureVersion]
Measure=WebParser
URL=[measureData]
StringIndex=15
RegExpSubstitute=1
Substitute='(.+)':"\[\1\]", "\\":""

[measureImage]
Measure=WebParser
URL=https://assets.ppy.sh/beatmaps/[measureData]/covers/list@2x.jpg?
StringIndex=13
Download=1
DownloadFile=cover.jpg

[measureID]
Measure=WebParser
URL=[measureData]
StringIndex=14

[measureMuted]
Measure=Calc
Formula=#Muted#
IfCondition=measureMuted = 0
IfTrueAction=[!SetVariable ToggleMuted 1][!SetOption meterToggleMute Text volume-high][!UpdateMeter meterToggleMute][!Redraw]
IfFalseAction=[!SetVariable ToggleMuted 0][!CommandMeasure SpeechHost ""][!SetOption meterToggleMute Text volume-xmark][!UpdateMeter meterToggleMute][!Redraw]
DynamicVariables=1

[meterImage]
Meter=Image
MeasureName=measureImage
DynamicVariables=1
H=[meterLabel:H]
LeftMouseUpAction=osu://b/[measureID]
RightMouseUpAction=https://osu.ppy.sh/beatmaps/[measureID]
ToolTipText=Left: In-game beatmap listing#CRLF#Right: Website
ToolTipTitle=Actions
Container=meterImageContainer

[meterImageContainer]
Meter=Shape
Shape=Rectangle 0,0,[meterLabel:H],[meterLabel:H],#CornerRadius# | StrokeWidth 0
DynamicVariables=1
X=(#Width# - [meterLabel:H])

[meterLabelBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterLabel:W],[meterLabel:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup

[meterLabel]
Meter=String
FontSize=22
FontFace=#DisplayFont#
AntiAlias=1
W=(#Width# - (#SidePadding# * 2))
Padding=#PaddingSize#
Group=TextGroup

[meterLoadingBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterLoading:W],[meterLoading:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | LoadingGroup
Y=R

[meterLoading]
Meter=String
Group=TextGroup | LoadingGroup
Text=Loading...
FontSize=14
FontFace=#FontFace#
AntiAlias=1
Y=r
X=(#Width# / 2)
W=(#Width# - (#SidePadding# * 2))
StringAlign=Center
Padding=#PaddingSize#

[measureLoop]
Measure=Loop
StartValue=0
EndValue=9

[meterSpinnerBackground]
Meter=Shape
Shape=Rectangle 0,0,#Width#,40,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | LoadingGroup
Y=R

[meterLoadingSpinner]
Meter=String
FontFace=#IconFace#
FontSize=14
Text=[\xf110]
DynamicVariables=1
Angle=([measureLoop] / 5 * PI)
AntiAlias=1
Y=r
X=(#Width# / 2)
W=0
H=2
Padding=0,20,0,0
StringAlign=CenterCenter
Group=LoadingGroup | TextGroup

[meterDataBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterData:W],[meterData:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | Content
Y=R

[meterData]
Meter=String
MeasureName=measureScore
MeasureName2=measureMaxCombo
MeasureName3=measure300
MeasureName4=measure100
MeasureName5=measure50
MeasureName6=measureMiss
MeasureName7=measurePP
MeasureName8=measureVersion
MeasureName9=measureTitle
MeasureName10=measureAccuracy
MeasureName11=measureTimeAgo
MeasureName12=measureTimeLabel
FontSize=14
FontFace=#FontFace#
AntiAlias=1
Y=r
W=(#Width# - (#SidePadding# * 2))
ClipString=2
Text=%9%8#CRLF#%1 | %2 | %3/%4/%5/%6 | %10 | %7#CRLF#%11%12
Padding=#PaddingSize#
Group=TextGroup | Content
Hidden=1

[meterRankAndModBackground]
Meter=Shape
Shape=Rectangle 0,0,#Width#,([meterRank:H] + (#SidePadding# * 2)), #CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
Y=R
DynamicVariables=1
Group=Content | BackgroundGroup
Hidden=1

[meterRank]
Meter=String
MeasureName=measureRankDisplay
AntiAlias=1
H=20
FontFace=#IconFace#
FontSize=18
DynamicVariables=1
Y=(([meterRankAndModBackground:H] - [meterRank:H]) / 2)r
Padding=#SidePadding#,0,5,0
Group=Content
Hidden=1

[meterMods]
Meter=String
MeasureName=measureMods
FontSize=14
FontFace=#FontFace#
AntiAlias=1
X=R
DynamicVariables=1
H=(10 + #SidePadding# * 2)
Y=r
Padding=5,0,0,0
Group=TextGroup | Content
Hidden=1

[meterDropdownBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterDropdown:W],[meterDropdown:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
Shape2=Rectangle 0,-#CornerRadius#,[meterDropdown:W],[meterDropdown:H],0
Shape3=Rectangle 0,(-#CornerRadius# * 2),[meterDropdown:W],(#CornerRadius# * 2),#CornerRadius#
Shape4=Combine Shape | Union Shape2 | Exclude Shape3
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup
Y=R

[meterDropdown]
Meter=String
MeasureName=measureExtendedStats
Y=r
FontSize=10
FontFace=#MonospacedFontFace#
AntiAlias=1
ClipString=2
Padding=#PaddingSize#
W=(#Width# - (#SidePadding# * 2))
Group=TextGroup
Hidden=1

[ArrowExpandCollapseStyle]
AntiAlias=1
FontFace=#IconFace#
FontSize=16
Y=r
X=(#Width# / 2)
W=#Width#
H=20
Padding=0,#SidePadding#,0,#SidePadding#
StringAlign=Center
Hidden=1

[meterDownArrowBackground]
Meter=Shape
Shape=Rectangle 0,0,#Width#,(20 + #SidePadding# * 2), #CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
Shape2=Rectangle 0,-#CornerRadius#,#Width#,(20 + #SidePadding# * 2),0
Shape3=Rectangle 0,(-#CornerRadius# * 2),#Width#,(#CornerRadius# * 2),#CornerRadius#
Shape4=Combine Shape | Union Shape2 | Exclude Shape3
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | DownArrowGroup
Y=R
Hidden=1
MouseOverAction=[!SetOption meterDownArrowHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterDownArrowHover][!Redraw]
MouseLeaveAction=[!SetOption meterDownArrowHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterDownArrowHover][!Redraw]
ToolTipText=Expand extended stats.

[meterDownArrowHover]
Meter=Shape
Shape=Rectangle 0,0,#Width#,(20 + #SidePadding# * 2), #CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0
DynamicVariables=1
Group=DownArrowGroup
Y=r
Hidden=1

[meterDownArrow]
Meter=String
MeterStyle=ArrowExpandCollapseStyle
Text=[\xf078]
LeftMouseUpAction=#VerticalExpandCommand#[!SetVariable UserCollapsed 0]
Group=TextGroup | DownArrowGroup
Hidden=1

[meterUpArrowBackground]
Meter=Shape
Shape=Rectangle 0,0,#Width#,(20 + #SidePadding# * 2), #CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | UpArrowGroup
Y=R
Hidden=1
MouseOverAction=[!SetOption meterUpArrowHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterUpArrowHover][!Redraw]
MouseLeaveAction=[!SetOption meterUpArrowHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterUpArrowHover][!Redraw]
ToolTipText=Collapse extended stats.

[meterUpArrowHover]
Meter=Shape
Shape=Rectangle 0,0,#Width#,(20 + #SidePadding# * 2), #CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0
DynamicVariables=1
Group=UpArrowGroup
Y=r
Hidden=1

[meterUpArrow]
Meter=String
MeterStyle=ArrowExpandCollapseStyle
Text=[\xf077]
;LeftMouseUpAction=[!HideMeter meterDropdown][!HideMeter meterDropdownBackground][!HideMeterGroup UpArrowGroup][!ShowMeterGroup DownArrowGroup][!SetVariable UserCollapsed 1][!Redraw]
LeftMouseUpAction=[!HideMeterGroup UpArrowGroup][!ShowMeterGroup DownArrowGroup]#VerticalCollapseCommand#[!SetVariable UserCollapsed 1]
Group=TextGroup | UpArrowGroup
Hidden=1

[meterToggleMute]
Meter=String
Group=TextGroup
FontFace=#IconFace#
DynamicVariables=1
Padding=#PaddingSize#
FontSize=16
AntiAlias=1
MouseOverAction=[!SetOption meterToggleMute SolidColor #LightHighlight#,#NoGradientTransparency#][!UpdateMeter meterToggleMute][!Redraw]
MouseLeaveAction=[!SetOption meterToggleMute SolidColor 0,0,0,0][!UpdateMeter meterToggleMute][!Redraw]
LeftMouseUpAction=[!WriteKeyValue Variables Muted #ToggleMuted#][!SetVariable Muted #ToggleMuted#][!UpdateMeasure measureMuted]
Container=meterToggleMuteContainer
OnUpdateAction=[!UpdateMeter meterToggleMuteContainer]

[meterToggleMuteContainer]
Meter=Shape
Shape=Rectangle 0,0,[meterToggleMute:W],[meterToggleMute:H],#CornerRadius# | StrokeWidth 0
DynamicVariables=1
X=([meterData:W] - [meterToggleMute:W])
Y=([meterData:Y] + [meterData:H]- [meterToggleMute:H])
Group=Content
