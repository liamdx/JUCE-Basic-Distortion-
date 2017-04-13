/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
NonLinearPracticeAudioProcessor::NonLinearPracticeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

NonLinearPracticeAudioProcessor::~NonLinearPracticeAudioProcessor()
{
}

//==============================================================================
const String NonLinearPracticeAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NonLinearPracticeAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool NonLinearPracticeAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double NonLinearPracticeAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NonLinearPracticeAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int NonLinearPracticeAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NonLinearPracticeAudioProcessor::setCurrentProgram (int index)
{
}

const String NonLinearPracticeAudioProcessor::getProgramName (int index)
{
    return String();
}

void NonLinearPracticeAudioProcessor::changeProgramName (int index, const String& newName)
{
}


//==============================================================================
void NonLinearPracticeAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void NonLinearPracticeAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NonLinearPracticeAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void NonLinearPracticeAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    
    
    
    double input = 0.f;
    double output = 0.f;
    float currentGain = gain;
    float currentBoost = boost;
    float currentOverdrive = overdrive;
    
    
    if(optionState == 0){
        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {
            float* channelData = buffer.getWritePointer (channel);
            
            for(int i = 0; i < buffer.getNumSamples(); i++)
            {
                input = channelData[i]* currentGain;
                //float k = (2 * currentOverdrive) / (currentBoost - currentOverdrive);
                //output = (currentBoost + k) * input / (currentBoost + k * std::abs(input));
                if(input < currentBoost){
                    output = input;
                }else if(input > currentBoost){
                    output = currentBoost + (input - currentBoost)/ (1+pow(((input-currentBoost)/(1-currentBoost)),2));
                }else if(input > 1){
                    output = (currentBoost + 1) / 2;
                }
                
                channelData[i] = output;
            }
        }
    }else if(optionState == 1){
        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {
            float* channelData = buffer.getWritePointer (channel);
            
            for(int i = 0; i < buffer.getNumSamples(); i++)
            {
                input = channelData[i] * currentGain;;
                const double x = input * 0.686306;
                const double a = currentBoost + exp(sqrt(fabs(x)) * -0.75);
                channelData[i] = (exp(x) -exp(-x * a))/ (exp(x) + exp(-x));
            }
        }
    }
    else if (optionState == 2){
        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {
            float* channelData = buffer.getWritePointer (channel);
            
            for(int i = 0; i < buffer.getNumSamples(); i++)
            {
                float calculatedGain = ((currentBoost/100)* 100) + 1;
                input = channelData[i] * calculatedGain;
                float a = sin(((currentOverdrive+1)/101)*(pi/2));
                float k = 2 * a / (1-a);
                output = (1 +k) * input/(1 + k * abs(input));
                channelData[i] = output;
            }
        }
        
    }
    
}

//==============================================================================
bool NonLinearPracticeAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* NonLinearPracticeAudioProcessor::createEditor()
{
    return new NonLinearPracticeAudioProcessorEditor (*this);
}

//==============================================================================
void NonLinearPracticeAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void NonLinearPracticeAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NonLinearPracticeAudioProcessor();
}
