let ps = document.querySelectorAll("p");
let cont = 0;
for(let i = 0; i < ps.length; i++){
    cont++;
}

let mostrar = document.createElement("h1");
mostrar.innerText = `${cont}`;
document.body.appendChild(mostrar);

