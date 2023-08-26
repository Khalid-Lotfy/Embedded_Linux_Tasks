# use webbrowser module to open firefox on a site that suggests an activity

import webbrowser


#open firefox from its path  and open the site that suggests activities
webbrowser.get("/snap/bin/firefox").open("https://www.boredapi.com/api/activity")