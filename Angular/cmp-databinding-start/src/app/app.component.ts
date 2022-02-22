import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  // kod JavaScript tworzę tablicę elementów: key: 'value' zawierającą jeden obiekt
  serverElements = [
    {type: 'server', name: 'Testserver', content: 'Just a test!'},
    {type: 'blueprint', name: 'DrugiTest', content: 'Twice test'}];

  onServerAdded(serverData: {serverName: string, serverContent: string }) {
    this.serverElements.push({
      type: 'server',
      name: serverData.serverName,
      content: serverData.serverContent
    });
  }

  onBlueprintAdded(blueprintData: {serverName: string, serverContent: string }) {
    this.serverElements.push({
      type: 'blueprint',
      name: blueprintData.serverName,
      content: blueprintData.serverContent
    });
  }


}
