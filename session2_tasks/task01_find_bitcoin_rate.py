#code to find bitcoin rate in dollar and Euro

'''
the shape of json file of the our website
{

   "time":{

      "updated":"Aug 10, 2023 14:36:00 UTC",

      "updatedISO":"2023-08-10T14:36:00+00:00",

      "updateduk":"Aug 10, 2023 at 15:36 BST"

   },

   "disclaimer":"This data was produced from the CoinDesk Bitcoin Price Index (USD). Non-USD currency data converted using hourly conversion rate from openexchangerates.org",

   "chartName":"Bitcoin",

   "bpi":{

      "USD":{

         "code":"USD",

         "symbol":"&#36;",

         "rate":"29,589.6523",

         "description":"United States Dollar",

         "rate_float":29589.6523

      },

      "GBP":{

         "code":"GBP",

         "symbol":"&pound;",

         "rate":"24,724.8767",

         "description":"British Pound Sterling",

         "rate_float":24724.8767

      },

      "EUR":{

         "code":"EUR",

         "symbol":"&euro;",

         "rate":"28,824.6414",

         "description":"Euro",

         "rate_float":28824.6414

      }

   }

}


'''

import requests

url=requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")

print(url.json()["time"]["updated"])
print("Bitcoin rate in dollar:    ", url.json()["bpi"]["USD"])
print("Bitcoin rate in euros:     ", url.json()["bpi"]["EUR"])
