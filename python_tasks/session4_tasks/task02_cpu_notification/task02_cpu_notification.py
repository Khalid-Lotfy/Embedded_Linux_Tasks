#from pynotifier import Notification
import psutil
from plyer import notification

cpu_freq=psutil.cpu_freq()  #current cpu frequency

notification.notify(
            #notification heading
            title = "CPU frequency",
            #notification body
            message="CPU frequency is: "+str(round(cpu_freq.current,3))+" MHZ",
           
            # displaying time
            timeout=10
)