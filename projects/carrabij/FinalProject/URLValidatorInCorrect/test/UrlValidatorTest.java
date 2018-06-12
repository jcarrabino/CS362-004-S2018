/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
import junit.framework.TestCase;
import java.util.Random;

public class UrlValidatorTest extends TestCase {
   public UrlValidatorTest(String testName) {
      super(testName);
   }
/*
 * CS362 Final Project: John Carrabino, David Pardy, and Leigh Ann Pruitt
 * ONIDs: Carrabij, Pardyd, Pruittl 
 * Date: 06/11/2018
 */ 
 
   public void manualTest() {
		ResultPair[] urlTests = {
				new ResultPair("http://google.com", true),
				new ResultPair("http://www.github.com/jcarrabino", true),
				new ResultPair("http://www.reddit.com", true),
				new ResultPair("http://www.amazon.com", true),
				new ResultPair("https://www.google.it", true),
				new ResultPair("https://www.google.co.jp", true),
				new ResultPair("http://www.oregonstate.edu", true),
				new ResultPair("httP://www.cnn.com", true),
				new ResultPair("httP://www.msnbc.com", true),
				new ResultPair("ftp://127.0.0.1", true),
				new ResultPair("https://www.apple.com/", true),
				new ResultPair("http:\\1234.567.890.1", false),
				new ResultPair("http//\fake.apple.com/iphone/", false),
				new ResultPair("httpr://wwww.amazon.com/", false),
				new ResultPair("http;\\www.google.com", false),
				new ResultPair("ftpq://yyy.oregonstate.edu", false),
				new ResultPair("ftp:12345.0.1230.1", false)};
        
   	int urlIndex = 0;
   	String expected, returned;    
   	boolean isExpected, isReturned;
    
   	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
   	System.out.println("____________________________________________________________");
   	System.out.println("                                                            ");
   	System.out.println("                         MANUAL TESTS                       ");
   	System.out.println("____________________________________________________________");
   	while (urlIndex < urlTests.length) {   
	   // Value in ResultPair
	   isExpected = urlTests[urlIndex].valid;
	   expected = (isExpected) ? "VALID" : "INVALID"; 
	   // Value returned from isValid()
	   isReturned = urlVal.isValid(urlTests[urlIndex].item);
	   returned = (isReturned) ? "VALID" : "INVALID";
	   	// Test failed
	   	if (expected != returned) {
			System.out.println("TESTING " + expected + " URL: " + urlTests[urlIndex].item);
			System.out.println("- TEST FAILED.\n - EXPECTED: " + expected + ".\n - RETURNED: " + returned + "\n"); 
	   	}
	   	// Test passed
	   	else
			System.out.println("TESTING " + expected + " URL: " + urlTests[urlIndex].item);
	   	urlIndex++;
   	}
   	System.out.println("\n______________________________\n");
	}

   
 //four parts of URL string to be tested: scheme, authority, path, query

 	//scheme test
    public void testScheme() {
 	   System.out.println("First Partition Test: Test Scheme of URL String");
 	   //test valid input and invalid input, then unknown input
 	   //URL validator should return true, false, and false
 	   String[] urlSchemeInput = {"ftp://", "http/", "http:////"};
 	   UrlValidator schemeString = new UrlValidator(urlSchemeInput, 0);

 	   for (int i = 0; i < urlSchemeInput.length; i++) {
 		   String schemeStringTest = urlSchemeInput[i];
 		   System.out.println("Test for scheme validity: string -  " + schemeStringTest);
 		   String newTestSchemeString = schemeStringTest;
 		   boolean isValidString = schemeString.isValidScheme(newTestSchemeString);
 		   System.out.println("Expected test results: true, false, and false.");
 		   if (isValidString == false)
 			   System.out.println("URL Validator Test Result: False. Scheme not valid.");
 		   else
 			   System.out.println("URL Validator Test Result: True: Scheme valid.");
 	    }
 	   	System.out.println("\n\n\n\n\n");
    }


    //authority test
    public void testAuthority() {
 	   System.out.println("Second Partition Test: Test Authority of URL String");
 	   //test valid input and invalid input, then unknown input
 	   //URL validator should return true, false, and false
 	   String[] urlSchemeInput = {"www.google.com", "1.2.3", "www.google.com/1.2.3"};
 	   UrlValidator authorityString = new UrlValidator(urlSchemeInput, 0);

 	   for (int i = 0; i < urlSchemeInput.length; i++) {
 		   String authorityStringTest = urlSchemeInput[i];
 		   System.out.println("Test for authority validity: string -  " + authorityStringTest);
 		   String newTestAuthorityString = authorityStringTest;
 		   System.out.println("Expected test results: true, false, and false.");
 		   boolean isValidString = authorityString.isValidAuthority(newTestAuthorityString);
 		   if (isValidString == false)
 			   System.out.println("URL Validator Test Result: False. Authority not valid.");
 		   else
 			   System.out.println("URL Validator Test Result: True: Authority valid.");
 	    }
 	   	System.out.println("\n\n\n\n\n");
    }
   
   // port test
   public void testPort() {
     System.out.println("Third Partition Test: Test Port of URL String");
 	   //test valid input and invalid input, then unknown input
 	   //URL validator should return true, false, and false
     String[] urlPortInput = {":65535", ":-1", ":65535:-1"};
     UrlValidator portString = new UrlValidator(urlPortInput, 0);

     for (int i = 0; i < urlPortInput.length; i++) {
       String portStringTest = urlPortInput[i];
       System.out.println("Test for port validity: string - " + "www.google.com:" + portStringTest);
       String newTestPortString = "www.google.com:" + portStringTest;
       boolean isValidString = portString.isValidAuthority(newTestPortString);

       System.out.println("Expected test results: true, false, and false.");

       if (isValidString == false)
        System.out.println("URL Validator Test Result: False. Port not valid.");
       else
     	  	System.out.println("URL Validator Test Result: True: Port valid.");

    	System.out.println("\n\n\n\n\n");
   }
   }

   // path test
   public void testPath(){
     System.out.println("Third Partition Test: Test Port of URL String");
 	   //URL validator should return true, false, and false
     String[] urlPathInput = {"/$23", "/..", "/$23/.."};
     UrlValidator pathString = new UrlValidator(urlPathInput, 0);

     for (int i = 0; i < urlPathInput.length; i++) {
       String pathStringTest = urlPathInput[i];
       System.out.println("Test for port validity: string - " + pathStringTest);
       String newTestPathString = pathStringTest;
       boolean isValidString = pathString.isValidPath(newTestPathString);
       if (isValidString == false)
         System.out.println("URL Validator Test Result: False. Path not valid.");
       else
     	  	System.out.println("URL Validator Test Result: True: Port valid.");
     }
    	System.out.println("\n\n\n\n\n");
   }

   
}


