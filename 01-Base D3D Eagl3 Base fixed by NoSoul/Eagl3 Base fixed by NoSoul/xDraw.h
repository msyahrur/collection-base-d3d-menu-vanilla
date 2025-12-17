

void BoxColor(int x, int y, int w, int h, D3DCOLOR Color,LPDIRECT3DDEVICE9 pDevice)
{
	struct Vertex
	{
		float x,y,z,ht;
		DWORD Color;
	};
	DWORD ColorBG;
	Vertex V[8];

	V[0].Color = V[1].Color = V[2].Color = V[3].Color = Color;
	V[0].z  = V[1].z   = V[2].z   = V[3].z   = 0.0f;
	V[0].ht = V[1].ht  = V[2].ht  = V[3].ht  = 0.0f;

	V[0].x = V[1].x = (float)x;
	V[0].y = V[2].y = (float)(y + h);
	V[1].y = V[3].y = (float)y;
	V[2].x = V[3].x = (float)(x + w);

	pDevice->SetTexture(0, NULL);
	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1); 
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,V,sizeof(Vertex));
} 



void BoxColor_s(LPDIRECT3DDEVICE9 pDevice , int x, int y, int w, int h, DWORD Color)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, Color, 0, 0 );
}

void BorderColor(int x, int y, int w, int h, int s, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
	BoxColor_s(pDevice, x, y, w, s, Color);
	BoxColor_s(pDevice, x, y, s, h, Color);
	BoxColor_s(pDevice, (x+w), y, s, h, Color);
	BoxColor_s(pDevice, x, (y+h), w+s, s, Color);
}

