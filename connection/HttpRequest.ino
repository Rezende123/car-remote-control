String getCommand()
{
  http.begin(BASE_URL);
  http.addHeader("Content-type", "application/x-www-form-urlencoded");
  
  String response = "";
  int httpCode = http.GET();//Send the request
   
  if (httpCode > 0)//Check the returning code
    response = http.getString();//Get the request response payload
          
  http.end();
  return response;
}
