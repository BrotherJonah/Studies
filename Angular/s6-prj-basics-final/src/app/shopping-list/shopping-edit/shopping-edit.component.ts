import {Component, OnInit, ViewChild, ElementRef, EventEmitter, Output} from '@angular/core';
import {Ingredient} from '../../shared/ingredient.model';

@Component({
  selector: 'app-shopping-edit',
  templateUrl: './shopping-edit.component.html',
  styleUrls: ['./shopping-edit.component.css']
})
export class ShoppingEditComponent implements OnInit {
  @ViewChild('nameInput', {static: false}) nameInputRef: ElementRef;
  @ViewChild('amountInput', {static: false}) amountInputRef: ElementRef;
  @Output() ingerdientAdded = new EventEmitter<Ingredient>();

  constructor() { }
  onAddItem() {
    const ingName = this.nameInputRef.nativeElement.value;
    const ingAmount = this.amountInputRef.nativeElement.value;
    const newIngredient = new Ingredient(ingName, ingAmount);
    this.ingerdientAdded.emit(newIngredient);
  }
  ngOnInit() {
  }

}
