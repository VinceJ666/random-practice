#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jun 16 16:21:17 2023

@author: vince
"""


import requests 
from datetime import datetime
import re
from bs4 import BeautifulSoup      



def check_new_listing(ancmt):
    if 'Binance Will List' in ancmt['title'] or 'Token Sale on Binance Launchpad Is Now Open' in ancmt['title'] or 'Introducing' in ancmt['title'] and 'Token Sale on Binance Launchpad' in ancmt['title']:
        ticker=ancmt['title'].split('(')[1].split(')')[0]
        print(ticker)        
        print(ancmt['releaseDate'])
        print(ancmt['title'])
        return ticker
    else:
        return None
   
if __name__ == "__main__":     
    print('start scrap binance')  
    url = 'https://www.binance.com/en/support/announcement/c-48?navId=48'
    strhtml = requests.get(url)       
    soup=BeautifulSoup(strhtml.text,features='lxml')
    data = soup.find("script",attrs=({'id':"__APP_DATA", 'type':"application/json"})).text
    data1 = re.search(r'"catalogName":"New Cryptocurrency Listing"(.*){"catalogId":49',data).group()
    data1 = re.search(r'"articles"(.*)"catalogs"',data1).group()
    data1 = data1.split("},{")
    data1[0]=data1[0].replace('"articles":[{','')
    data1[-1]=data1[-1].replace('}],"catalogs"','')
    for i in data1:
        exec('ancmt={'+i+'}')
        ancmt["releaseDate"]=datetime.fromtimestamp(ancmt["releaseDate"]/1000)
        ancmt["url"]='https://www.binance.com/en/support/announcement/'+ancmt["code"]    
        check_new_listing(ancmt)


