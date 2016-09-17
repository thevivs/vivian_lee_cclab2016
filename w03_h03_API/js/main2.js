var app = app || {};


app.main = (function(){

  console.log('Loading app.');


  var attachEvents = function(){

    console.log('Attaching events.');

    //I think this is saying that when you click on button 
    //it will submit from the search box


    $('#buttonOne').off('click').on('click', function(){
      loadData($('#search').val());
      // console.log("what the hell is this:" +$('#search-box').val());
    });

    $('#boxOne').keypress(function(e) {
      if (e.keyCode == 13) {
        loadData($('#boxOne').val());
      }
    });
  };

 

 //grab data from API
  var loadData = function(query){
    console.log('Searching for ' + query + '...');

    var giphyUrl="http://api.giphy.com/v1/gifs/search?q="+query+"&api_key=dc6zaTOxFJmzC";
  
      $.ajax({
          url: giphyUrl,
          data:{
            q:query,
            limit:1   //limit 1

          },

          //if it succesfully gets data, you will add the reponse
          success: function (response) {
         
        console.log("response is:"+response.data);

       
        // console.log('Found ' + results.length + ' results.');

        appendData(response.data);
          }
      });

  };



//load data from API to "view"
  var appendData = function(data){
    console.log('Appending data.');
    console.log(data);

   
    $('#comicPanel').empty();

//this we dont need vvvv
    // $('html, body').animate({
    //         scrollTop: $('#view').offset().top + 'px'
    //     }, 'slow');


    // 3.
    for(var i = 0; i < data.length; i++){
      $('#comicPanel').append('<img src="' + data[i].images.downsized.url + '" class="gallery-item"/>');
    }
  };

//this we dont need ^^^^^^

  // 1.
  var init = function(){
    console.log('Initializing app.');
    attachEvents();
  };

  return {
    init: init
  };
})();

window.addEventListener('DOMContentLoaded', app.main.init);
