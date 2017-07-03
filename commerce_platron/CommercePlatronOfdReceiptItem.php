<?php

class CommercePlatronOfdReceiptItem
{
	public $label;
	public $amount;
	public $price;
	public $quantity;
	public $vat;

	public function toArray()
	{
		return array(
			'pg_label' => extension_loaded('mbstring') ? mb_substr($this->label, 0, 128) : substr($this->label, 0, 128),
			'pg_amount' => $this->amount,
			'pg_price' => $this->price,
			'pg_quantity' => $this->quantity,
			'pg_vat' => $this->vat,
		);
	}
}
