/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NonLinearPracticeAudioProcessorEditor::NonLinearPracticeAudioProcessorEditor (NonLinearPracticeAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderBoost = new Slider ("boostSlider"));
    sliderBoost->setRange (0, 1, 0);
    sliderBoost->setSliderStyle (Slider::LinearHorizontal);
    sliderBoost->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderBoost->addListener (this);

    addAndMakeVisible (sliderGain = new Slider ("gainSlider"));
    sliderGain->setRange (0, 1, 0);
    sliderGain->setSliderStyle (Slider::LinearHorizontal);
    sliderGain->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderGain->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Boost")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Gain")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);//starts timer with interval of 200mS
    //[/Constructor]
}

NonLinearPracticeAudioProcessorEditor::~NonLinearPracticeAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderBoost = nullptr;
    sliderGain = nullptr;
    label = nullptr;
    label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NonLinearPracticeAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NonLinearPracticeAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderBoost->setBounds (40, 32, 150, 24);
    sliderGain->setBounds (40, 88, 150, 24);
    label->setBounds (216, 32, 150, 24);
    label2->setBounds (216, 88, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void NonLinearPracticeAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderBoost)
    {
        //[UserSliderCode_sliderBoost] -- add your slider handling code here..
        //[/UserSliderCode_sliderBoost]
        processor.boost = sliderBoost->getValue();
    }
    else if (sliderThatWasMoved == sliderGain)
    {
        //[UserSliderCode_sliderGain] -- add your slider handling code here..
        //[/UserSliderCode_sliderGain]
        processor.gain = sliderGain->getValue();
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void NonLinearPracticeAudioProcessorEditor::timerCallback()
{
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NonLinearPracticeAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="StereoPannerAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="boostSlider" id="32bddd3f573a7444" memberName="sliderBoost"
          virtualName="" explicitFocusOrder="0" pos="40 32 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="gainSlider" id="4ad8d562c7b9cf" memberName="sliderGain"
          virtualName="" explicitFocusOrder="0" pos="40 88 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="new label" id="2e5ef8115e58828b" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="216 32 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Boost" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5593b3326a9d3207" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="216 88 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
