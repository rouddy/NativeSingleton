package com.rouddy.nativesingletonapp;

import com.rouddy.nativesingleton.NativeSingleton;

/**
 * Created by yoojaehong on 2017. 2. 11..
 */

public class TestSingleton extends NativeSingleton {

	private int value = 1;

	public static TestSingleton getInstance() {
		return (TestSingleton) TestSingleton.getInstance(TestSingleton.class);
	}

	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}
}
