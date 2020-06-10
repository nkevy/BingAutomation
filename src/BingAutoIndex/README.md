BingAutoIndex
=============

The src dir contains source code for the bingdex binary.
An example usage is shown bellow.

	$bingdex https://example.com
	$[Complete] A request to index the https://example.com website has been sent to the corresponding Bing Webmaster account.

Potential Errors
----------------
If there are errors that are not on the following list please rebuild the tool from source. 
Or list an issue. 
See https://github.com/nkevy/BingAutomation/tree/master/src/BingAutoIndex

1. You have not configure the key to access your Bing Webmaster account. 
See https://docs.microsoft.com/en-us/bingwebmaster/getting-access

2. There are no .html files in the folder or directory. Please run the bingdex tool from the folder or directory that contains the .html files used to generate your website.

3. You have entered your website incorrectly. Enter the website after the bindex tool with the http:// or https:// and omit the any trailing characters such as / or \. Please see the usage.

Usage
-----

$bingdex <your website here.>

Instead of <your website here> type https://example.com 
