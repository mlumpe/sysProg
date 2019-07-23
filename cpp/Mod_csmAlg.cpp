#pragma once

bool csmAlg(CSMInstance x){
	int ia = 0;
	int ib = 0;
	
	if(coa(x) == 0 && cob(x) == 0)
		return true;
	if(coa(x) == 0 || cob(x) == 0)
		return false;
	
	int la = lena(x, 0);
	int lb = lenb(x, 0);
	
	int acta = 0;
	int actb = 0;
	
	int minl = sp_min(la,lb);
	
	while(ia < coa(x) && ib < cob(x)){
		if(!ssc(x, ia, ib, acta, actb, minl)){
			return false;
		}
		
		acta += minl;
		actb += minl;
		
		if(acta == la){
			ia++;
			la = lena(x, ia);
			acta = 0;
		}
        
		if(actb == lb){
			ib++;
			lb = lenb(x, ib);
			actb = 0;
		}
		
		minl = sp_min(la-acta, lb-actb);
	}
	
	if(ia < coa(x) || ib < cob(x))
		return false;
	
	return true;
}
