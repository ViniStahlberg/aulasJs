

document.getElementById("contador").addEventListener("click", (e) => {
    let cont = document.querySelector("h1");
    let numero = Number(cont.innerText);

    numero += 1;

    cont.innerText = numero;
     
});

