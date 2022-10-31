[Variables]
DropdownHeight=500
RepeatRate=1
;for optimization purposes
;RepeatRate=16
;testing purposes
;RepeatRate=1000
Duration=20

EaseOutQuint=(#DropdownHeight# - (#SidePadding# * 2) - (((#Duration# - [measureMultiplier]) ** 5)) / ((#Duration# ** 5) / #DropdownHeight#))
EaseInQuint=(#DropdownHeight# - (#SidePadding# * 2) - (((#Duration# - [measureMultiplier]) ** 5)) / ((#Duration# ** 5) / #DropdownHeight#))

BaseVerticalExpand=ShowDropdown | Repeat VerticalExpand,#RepeatRate#,#Duration#
BaseVerticalCollapse=Repeat VerticalCollapse,#RepeatRate#,#Duration# | HideDropdown

BaseHorizontalExpand=ShowDropdown | Repeat HorizontalExpand,#RepeatRate#,#Duration#
BaseHorizontalCollapse=Repeat HorizontalCollapse,#RepeatRate#,#Duration# | HideDropdown

VerticalExpandCommand=[!CommandMeasure measureStateAnimation "Stop 2"][!CommandMeasure measureStateAnimation "Execute 1"]
VerticalCollapseCommand=[!CommandMeasure measureStateAnimation "Stop 1"][!CommandMeasure measureStateAnimation "Execute 2"]

HorizontalExpandCommand=[!CommandMeasure measureStateAnimation "Stop 4"][!CommandMeasure measureStateAnimation "Execute 3"]
HorizontalCollapseCommand=[!CommandMeasure measureStateAnimation "Stop 3"][!CommandMeasure measureStateAnimation "Execute 4"]

BaseHorizontalExpandAction=[!SetOption measureMultiplier Formula "(Clamp([measureMultiplier] + 1,0,#Duration#))"][!UpdateMeasure measureMultiplier][!SetOption meterDropdown W "#EaseOutQuint#"][!SetOption meterDropdownBackground W "#EaseOutQuint#"][!UpdateMeasure measureStateAnimation][!UpdateMeter meterDropdown][!UpdateMeter meterDropdownBackground][!Redraw]
BaseHorizontalCollapseAction=[!SetOption measureMultiplier Formula "(Clamp([measureMultiplier] - 1,0,#Duration#))"][!UpdateMeasure measureMultiplier][!SetOption meterDropdown W "#EaseInQuint#"][!SetOption meterDropdownBackground W "#EaseInQuint#"][!UpdateMeasure measureStateAnimation][!UpdateMeter meterDropdown][!UpdateMeter meterDropdownBackground][!Redraw]

[measureMultiplier]
Measure=Calc

[measureStateAnimation]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=#BaseVerticalExpand#
ActionList2=#BaseVerticalCollapse#
ActionList3=#BaseHorizontalExpand#
ActionList4=#BaseHorizontalCollapse#
ShowDropdown=[!ShowMeter meterDropdown][!ShowMeter meterDropdownBackground][!Redraw]
VerticalExpand=[!SetOption measureMultiplier Formula "(Clamp([measureMultiplier] + 1,0,#Duration#))"][!UpdateMeasure measureMultiplier][!SetOption meterDropdown H "#EaseOutQuint#"][!SetOption meterDropdownBackground H "#EaseOutQuint#"][!UpdateMeasure measureStateAnimation][!UpdateMeter meterDropdown][!UpdateMeter meterDropdownBackground][!Redraw]
VerticalCollapse=[!SetOption measureMultiplier Formula "(Clamp([measureMultiplier] - 1,0,#Duration#))"][!UpdateMeasure measureMultiplier][!SetOption meterDropdown H "#EaseInQuint#"][!SetOption meterDropdownBackground H "#EaseInQuint#"][!UpdateMeasure measureStateAnimation][!UpdateMeter meterDropdown][!UpdateMeter meterDropdownBackground][!Redraw]
HorizontalExpand=#BaseHorizontalExpandAction#
HorizontalCollapse=#BaseHorizontalCollapseAction#
HideDropdown=[!HideMeter meterDropdown][!HideMeter meterDropdownBackground][!Redraw]
