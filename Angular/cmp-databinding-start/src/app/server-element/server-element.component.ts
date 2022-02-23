import {Component, Input, OnInit, ViewEncapsulation, ViewChild, ElementRef, ContentChild} from '@angular/core';

@Component({
  selector: 'app-server-element',
  templateUrl: './server-element.component.html',
  styleUrls: ['./server-element.component.css'],
  encapsulation: ViewEncapsulation.Emulated
})
export class ServerElementComponent implements OnInit {
  // dodaję dekorator @input by móc zmieniać informację w propercie z zewnętrznego komponentu
  @Input('srvElement') element: {type: string, name: string, content: string};
  @ViewChild('heading', {static: true}) header: ElementRef;
  @ContentChild('contentParagraph', {static: true}) contentParagraph: ElementRef;

  constructor() { }

  ngOnInit(): void {
    console.log('ngOnInit called!');
    console.log('Tex tcontent' + this.header.nativeElement.textContent);
  }

}
