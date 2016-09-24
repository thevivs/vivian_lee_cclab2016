//set gif one to determine the gif
//get gif one to find from api
//load gif one to load into the thing



//functions to creat:
//loadweather function in class-example
//each submit corresponds to each panel


//loaddata function from giphy-example
//to grab data from giphy api
//is ajax just like json?

//append data
//grab from api load into panels



var gifOne;
var gifTwo;
var gifThree;
var gifFour;

//when DOM is ready do:

// when you submit in box# and button# it will correspond to each panel#


//init is what is starting the chain of events
//(init is the function that carries all functions)

$(document).ready(function() {
    init();
});

// var init = function(){    //init to allow submit
//  console.log("Whats the weather?");
//  $('#submit').click(function(e){   //click to do something 
//      e.preventDefault();    //e to return nothing if wrong
//      setlocation();          //look up location
//  });
// };


//sumbit something and click to get start functions
//and these functions are...

//for init I am individually setting functions for eadch button
//and they correspond to each loadGif# function
//which corresponds to each panel

//i.e fuction button one --> loadGifOne --> panelOne

var init = function() {

    console.log("gif?");

    //create function to read that there is an input in the search box
    //when you click on button one
    //it will take the value input into boxOne and do the function loadGif


    $('#buttonOne').click(function(e) {
        e.preventDefault();
        setGifOne();
        console.log($('#boxOne').val());
    });

};

var setGifOne = function() {
    gifOne = $('#buttonOne').val();


    getGifOne();

};


var getGifOne = function(query) {

    var giphyUrl = "http://api.giphy.com/v1/gifs/search?q=" + query + "&api_key=dc6zaTOxFJmzC";

    $.ajax({
        url: giphyUrl,
        data: {
            q: query,
            limit: 1
        },

        success: function(response) {
            console.log(response);



            console.log(response.data[0].images.downsized.url);

            testSource = response.data[0].images.downsized.url;
            loadGifOne(testSource);
        }

    });

};

//need to set 4 different submits that corresponds to each of the four panels
//loadGifOne is a function in wich it will grab query

var loadGifOne = function(url) {

    $('.comicPanel').append('<img src="' + url + '">');

}

//giphy.gif
