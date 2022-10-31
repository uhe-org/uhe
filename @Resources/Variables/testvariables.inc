[styleTestButton]
FontFace=#FontFace#
FontSize=16
AntiAlias=1
Group=TextGroup
Padding=#PaddingSize#
X=r
Y=r

[meterTestFinishActionBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterTestFinishAction:W],[meterTestFinishAction:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup
X=R

[meterTestFinishAction]
Meter=String
MeterStyle=styleTestButton
Text=TestFinishAction
LeftMouseUpAction=[!CommandMeasure measureData "Execute 1"]

[meterTestOnConnectErrorActionBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterTestOnConnectErrorAction:W],[meterTestOnConnectErrorAction:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup
X=r
Y=R

[meterTestOnConnectErrorAction]
Meter=String
MeterStyle=styleTestButton
Text=TestOnConnectErrorAction
LeftMouseUpAction=[!CommandMeasure measureData "Execute 2"]

[meterTestOnRegExpErrorActionBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterTestOnRegExpErrorAction:W],[meterTestOnRegExpErrorAction:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup
X=r
Y=R

[meterTestOnRegExpErrorAction]
Meter=String
MeterStyle=styleTestButton
Text=TestOnRegExpErrorAction
LeftMouseUpAction=[!CommandMeasure measureData "Execute 3"]
