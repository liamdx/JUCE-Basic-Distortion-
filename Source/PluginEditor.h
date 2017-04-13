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

#ifndef __JUCE_HEADER_822938EC14C53334__
#define __JUCE_HEADER_822938EC14C53334__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class NonLinearPracticeAudioProcessorEditor  : public AudioProcessorEditor,
                                               public Timer,
                                               public SliderListener,
                                               public ButtonListener
{
public:
    //==============================================================================
    NonLinearPracticeAudioProcessorEditor (NonLinearPracticeAudioProcessor& p);
    ~NonLinearPracticeAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    void sliderValueChanged();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    NonLinearPracticeAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> sliderBoost;
    ScopedPointer<Slider> sliderGain;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Slider> sliderOverdrive;
    ScopedPointer<Label> label3;
    ScopedPointer<ToggleButton> toggleMode1;
    ScopedPointer<ToggleButton> toggleMode2;
    ScopedPointer<ToggleButton> toggleMode3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NonLinearPracticeAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_822938EC14C53334__
