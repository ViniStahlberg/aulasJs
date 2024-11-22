window.addEventListener("mouseover",(e)=>{
if(e.target == document.getElementById("meuDiv")){
    document.getElementById("meuDiv").style.background = "blue";
}else{
    document.getElementById("meuDiv").style.background = "white";
}
})