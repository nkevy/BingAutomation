BingAutomation
==============

The BingAutomation git contains tool(s) that use the Bing Automation API for Bing Webmaster. 
Cpp is used to create binary tools. Binaries are included for Mac and Windows os (not yet done).
This project has the following structure:

	src:
		tool name:
			contains source cpp files
			Makefile
	bin:
		UNIX:
			contaitns Unix build
		WINDOWS:
			contains Windows build

Precondition: A Bing Webmaster account.

Tool(s):
--------
bingdex, a tool to automate the submition of URLS to Bing Webmaster Index tool. 
Example usage: 
	$cd mywebsite
	$bingdex
	$[Succsess] A request to index html files has been sent to BingWebmaster.


