

$(document).ready(function () {
    var move="1";
    document.onkeydown = function () {
        switch (event.keyCode) {
            case 37:
                move = "0";
                break;
            case 38:
                move = "2";
                break;
            case 39:
                move = "1";
                break;
            case 40:
                move = "3";
                break;
            default:
                move = "5";
                break;
        }
     }
    var c = document.getElementById("snakeRender");
    var canvasContext = c.getContext("2d");
    var ws = new WebSocket("ws://127.0.0.1:1080");
    ws.onopen=function () {
        ws.send("1");        
    };
    ws.onmessage = function (evt) {
        var data = jQuery.parseJSON(evt.data);
        ws.send(move);
        c.width = 500;
        c.height = 500;
        canvasContext.clearRect(0, 0, 500, 500);
        canvasContext.fillStyle = "red";
        canvasContext.fillRect(data.snakefood.x*10, data.snakefood.y*10, 10, 10);
        canvasContext.fillStyle = "green";
        console.log(data);
        for (i = 0; i < data.numberofsnakes; i++) {
            for (j = 0;j<data.snakebody[i].length;j++){
                canvasContext.fillRect(data.snakebody[i].point[j].x * 10, data.snakebody[i].point[j].y * 10, 10, 10);
            }
           



        }
       

    };
    
   

})
