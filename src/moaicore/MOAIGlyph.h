// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIGLYPH_H
#define	MOAIGLYPH_H

//================================================================//
// MOAIKernVec
//================================================================//
class MOAIKernVec :
	public USVec2D {
public:

	MOAIKernVec () { mX = 0; mY = 0; }

	u32			mName;
};

//================================================================//
// MOAIGlyph
//================================================================//
class MOAIGlyph {
private:

	u32			mCode;
	USRect		mUVRect;

	float		mWidth;
	float		mHeight;
	float		mYOff;
	
	float		mAdvanceX;
	float		mBearingX;

	USLeanArray < MOAIKernVec > mKernTable;
	
public:

	friend class MOAIFont;
	friend class MOAITextFrame;
	friend class MOAITextLayout;

	SET ( const USRect&, UVRect, mUVRect )
	
	SET ( float, AdvanceX, mAdvanceX )
	SET ( float, BearingX, mBearingX )
	
	GET_SET ( u32, Code, mCode )

	//----------------------------------------------------------------//
	void			Draw				( float points, float x, float y ) const;
	MOAIKernVec		GetKerning			( u32 name ) const;
	USRect			GetRect				( float points, float x, float y ) const;
					MOAIGlyph			();
					~MOAIGlyph			();
	void			ReserveKernTable	( u32 total );
	void			SerializeIn			( USLuaState& state );
	void			SerializeOut		( USLuaState& state );
	void			SetKernVec			( u32 id, const MOAIKernVec& kernVec );
	void			SetScreenRect		( float width, float height, float yOff );
};

#endif
