var gifOne;
var gifTwo;
var gifThree;
var gifFour;


$(document).ready(function() {
    init();
});



var init = function() {

    console.log("gif?");

    $('#buttonOne').click(function(e) {
        e.preventDefault();
        setGifOne();
        console.log($('#boxOne').val());
    });

    var setGifOne = function() {
        gifOne = $('#buttonOne').val();

    }

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

                            success: function (response) {
                            console.log(response);
                            loadGifOne(response.data);

                        }

                    });

                };

                //need to set 4 different submits that corresponds to each of the four panels


var loadGifOne =function(){

    $('#panelOne').append('<img src="giphyUrl"');

}