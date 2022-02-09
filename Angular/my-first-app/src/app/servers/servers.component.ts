import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-servers',
  // template: `
  //   <app-server></app-server>
  //   <app-server></app-server>`,
  templateUrl: './servers.component.html',
  styleUrls: ['./servers.component.css']
})
export class ServersComponent implements OnInit {
  allowNewServer = false;

  constructor() {
    //Konstruktor tworzy komponent w momencie wywołania
    //Metoda poniżej zmienia po 2 sekundach od załadowania strony stan allowNewServer na True.
    setTimeout(() => {
      this.allowNewServer = true;
     },2000)
   }

  ngOnInit(): void {
  }

}
