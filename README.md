BingAutomation
==============

The BingAutomation git contains tool(s) that use the Bing Automation API for Bing Webmaster. 
Cpp is used to create binary tools. Binaries are included for Mac and Windows os.
This project has the following structure:

	UNIX:
		src:
			contains source cpp files
		bin:
			contains unix binary
		Makefile
		
	WINDOWS:
		contaitns source cpp files
		
		Release:
			contains Windows executable
	WindowsBin:
		contains exe and dependencies.

Precondition: A Bing Webmaster account.

Tool(s):
--------
bingdex, a tool to automate the submition of URLS to Bing Webmaster Index tool. 
Example usage: 
	$cd mywebsite
	$bingdex
	$[Succsess] A request to index html files has been sent to BingWebmaster.


