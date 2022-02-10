import { Component } from "@angular/core";

@Component({
  selector: 'app-server',
  templateUrl: './server.component.html',
  styles: [`
    .online {
      color: white;
      }
  `]
})

export class ServerComponent{
  //String interpolation
  //W tym miejscu można dostarczyć treść do wyświetlnienia przez użytkownika np.: przez zapytanie HTTP albo przez jakiś back-end
  //Tworzę dwie propery aby je dostarczyć do template. Aby zapewnić połączenie z template w celu wyświetlenia treści dla użytkownika potrzebuje zapewnić data binding (komunikacje pomiędzy TypeScript a Template)
  serverId = 10;
  serverStatus: string = "offline";

  constructor(){
    this.serverStatus = Math.random() > 0.5 ? 'online' : 'offline';
  }

  getServerStatus(){
    return this.serverStatus;
  }

  getColor(){
    return this.serverStatus == 'online' ? 'green' : 'red';
  }
}
