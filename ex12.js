document.getElementById("mostrar").addEventListener("click", (e) => {
    let paragrafo = document.querySelector("p");
    if(paragrafo.style.display != "none"){
        paragrafo.style.display = "none";
    }else{
        paragrafo.style.display = "block";
    }
    
});