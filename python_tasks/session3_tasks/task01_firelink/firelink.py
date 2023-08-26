# module uses webbrowser module to open browser on a desired link

import webbrowser

websites={
'github_link':"https://github.com/",
'facebook_link':"https://ar-ar.facebook.com/",
'yallakora_link':"https://www.yallakora.com/",
'google_search':"https://www.google.com/webhp",
'youtube_link':"https://www.youtube.com/",
'whatsapp_web':"https://web.whatsapp.com/",
'valeo_careers':"https://valeo.wd3.myworkdayjobs.com/en-US/valeo_jobs"}


def firefox(link):
    webbrowser.get("/snap/bin/firefox").open(link)


   