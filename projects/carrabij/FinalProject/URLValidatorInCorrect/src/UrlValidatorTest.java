

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest() {
		ResultPair[] urlTests = {
				
                //Test cases for valid URLs
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
                
                //Test cases for invalid URLs
				new ResultPair("http:\\1234.567.890.1", false),
				new ResultPair("http//\fake.apple.com/iphone/", false),
				new ResultPair("httpr://wwww.amazon.com/", false),
				new ResultPair("http;\\www.google.com", false),
				new ResultPair("ftpq://yyy.oregonstate.edu", false),
				new ResultPair("ftp:12345.0.1230.1", false)
		    	};
                
		   	int urlIndex = 0;
		   	String expected, returned;
            
            // To match expected and returned
		   	boolean isExpected, isReturned; 
		   	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   	System.out.println("______________________________");
		   	System.out.println("|        MANUAL TESTS        |");
		   	System.out.println("______________________________");
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
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
