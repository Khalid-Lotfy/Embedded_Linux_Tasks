
import webbrowser
import time
import os
import playsound
import gtts
import speech_recognition as sr
import pyttsx3

r=sr.Recognizer()

# another way using pyttsx3 module
'''
engine = pyttsx3.init()

def speak(text):
    engine.say(text)
    engine.runAndWait()
'''
def speak(audio_text):
    tts=gtts.gTTS(text=audio_text,lang='en',slow=False)
    audiof='audio.mp3'
    tts.save(audiof)
    playsound.playsound(audiof)
    print(audio_text)
    os.remove(audiof)


def record(ask=False):
    with sr.Microphone(device_index=None) as source:
        r.adjust_for_ambient_noise(source)
        if ask:
            speak(ask)
        print("Listening...")
        audio=r.listen(source)  
        voice_data=""
        try:
            voice_data=r.recognize_google(audio,language='en-US')   
            print("=================================\n",voice_data,"\n=======================")
        except  sr.UnknownValueError:
            speak("I didn't get that")
        except sr.RequestError:
            speak("sorry Service is Down")
        return voice_data.lower()    


def respond(voice_data):
    if 'name' in voice_data or 'my name' in voice_data:
        speak('Khalid Lotfy Mohamed')
    if 'time' in voice_data or 'time now' in voice_data:
        speak(time.ctime())
    if  'search' in voice_data or 'browser' in voice_data or 'firefox' in voice_data or 'google' in voice_data:

        search=record('i will search for you')
        url='https://www.google.com.eg/search?q='+search
        webbrowser.get().open(url)

    if 'vs' in voice_data or 'vs code' in voice_data:
        os.system("gnome-terminal -e 'code'")

    if 'exit' in voice_data or 'thank you' in voice_data:
        exit()


while 1:
     voice_data=record()
     respond(voice_data)  


