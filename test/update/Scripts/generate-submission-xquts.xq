(: Schema for results :)
import schema default element namespace "http://www.w3.org/2005/02/query-test-XQTSResult" at "w3c_update_reportingresults/XQTSResult.xsd";

(: Test.xml file from ctest :)
declare variable $ctests as document-node() external;

if(fn:empty($ctests)) then
  fn:error()
else
  validate {
    <test-suite-result>
       <implementation name="Zorba" 
         version="trunk, r10831"
         anonymous-result-column="false">
  
      <organization
        name='zorba.io'
        website="http://zorba.io/"
        anonymous="false" />
    
      <submittor
        name="Zorba Team"
        email="contact@zorba.io" />
      
      <description>
        <p>Zorba is a general purpose XQuery processor implementing in C++
        the W3C family of specifications. It is not an XML database.
        The query processor has been designed to be embeddable in a
        variety of environments such as other programming languages
        extended with XML processing capabilities, browsers,
        database servers, XML message dispatchers, or smartphones.
        Its architecture employes a modular design, which allows customizing
        the Zorba query processor to the environment’s needs.
        For more details please check out http://www.zorba-xquery.com.</p>
      </description>
      
    {
      let $XQUTSZorba := fn:doc("XQUTS.xml")
      return
      (
        <implementation-defined-items>
        {
          for $idi in $XQUTSZorba//*:implementation-defined-item
          return
            <implementation-defined-item name="{data($idi/@name)}" value="{data($idi/@value)}" />
        }
        </implementation-defined-items>,
        <features>{$XQUTSZorba//*:feature}</features>,
        <context-properties>{$XQUTSZorba//*:context-property}</context-properties>
      )
    }
            
    </implementation>

    <syntax>XQueryX</syntax>
    
    <test-run dateRun="2012-05-09">
      <test-suite version="current"/>
      <transformation><p>Standard</p></transformation>
      <comparison><p>Standard</p></comparison>
      <otherComments><p>XQUTS version taken from CVS as of 2012-05-09.</p></otherComments>
    </test-run>
  
    {
      for $test in $ctests/*:Site/*:Testing/*:Test
      let $testname := fn:tokenize(fn:data($test/*:Name), "/")[last()]
      order by $testname
      return
      if(fn:exists(fn:index-of(('revalidation-declaration-01-fail','revalidation-declaration-03-fail','revalidation-declaration-05-fail','revalidate-valtrans-ins-003'
      ,'fn-put-003-fail','fn-put-004-fail','fn-put-006-fail'),$testname))) then
      <test-case
         name="{$testname}"
         result="not applicable"
         comment="This test was not run by Zorba: please consult the 'Guidelines for Running the XML Query Update Test Suite' for more details."
       />
      else if (fn:exists(fn:index-of(('fn-put-005'),$testname))) then
      <test-case
         name="{$testname}"
         result="not applicable"
         comment="Zorba does not support fn:put() for attibute nodes."
       />
      else if (fn:contains(fn:data($test),'StaticTypingFeature')) then
      <test-case
         name="{$testname}"
         result="not applicable"
         comment="Zorba does not support the 'Update Facility Static Typing Feature'"
       />
      else
       <test-case
         name="{$testname}"
         result="{fn:substring(fn:data($test/@Status), 0, 5)}"
       />
     }
  </test-suite-result>
}
