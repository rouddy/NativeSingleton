package com.rouddy.nativesingletonapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

	// Used to load the 'native-lib' library on application startup.
//	static {
//		System.loadLibrary("native-lib");
//	}

	TextView tv;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		// Example of a call to a native method
		tv = (TextView) findViewById(R.id.sample_text);
		Button btn = (Button) findViewById(R.id.button);
		btn.setOnClickListener(this);
//		tv.setText(stringFromJNI());
	}

	@Override
	public void onClick(View v) {
		int value = TestSingleton.getInstance().getValue();
		value += 1;
		tv.setText(String.valueOf(value));
		TestSingleton.getInstance().setValue(value);
	}

	/**
	 * A native method that is implemented by the 'native-lib' native library,
	 * which is packaged with this application.
	 */
//	public native String stringFromJNI();
}
