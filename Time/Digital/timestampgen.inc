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
W=280
Hidden=1
FontSize=18
FontFace=#DisplayFont#

[meterTimeUnitTitleBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterTimeUnitTitle:W],[meterTimeUnitTitle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup | TimestampGroup
Y=R
Hidden=1

[meterTimeUnitTitle]
Meter=String
Group=TextGroup | TimestampGroup
Text=Unit of Time
AntiAlias=1
Padding=#PaddingSize#
Y=r
W=280
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
X=50
W=100
StringAlign=Center
LeftMouseUpAction=[!SetOption measureTimeUnit String "Seconds"][!UpdateMeasure measureTimeUnit][!UpdateMeter meterSelectedUnit][!UpdateMeter meterSelectedUnitBackground][!Redraw]
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
X=100
Hidden=1

[measureMinButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=Minutes
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=50r
W=100
StringAlign=Center
LeftMouseUpAction=[!SetOption measureTimeUnit String "Minutes"][!UpdateMeasure measureTimeUnit][!UpdateMeter meterSelectedUnit][!UpdateMeter meterSelectedUnitBackground][!Redraw]
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
X=200
Hidden=1

[meterHrButton]
Meter=String
Group=TextGroup | TimestampGroup
Text=Hours
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=50r
W=100
StringAlign=Center
LeftMouseUpAction=[!SetOption measureTimeUnit String "Hours"][!UpdateMeasure measureTimeUnit][!UpdateMeter meterSelectedUnit][!UpdateMeter meterSelectedUnitBackground][!Redraw]
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
Shape=Rectangle 0,0,100,37,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup | TimestampGroup
Y=R
X=50
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
