import * as THREE from 'three';
// import { OrbitControls }from 'three/addons/loaders/OrbitControls.js';

// Set up scene
const scene = new THREE.Scene();

// Set up camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.z = 5;

// Set up renderer
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Load shaders
const loadShader = (id) => {
  return document.getElementById(id).innerText;
};

// Create Earth-like object
const earthGeometry = new THREE.SphereGeometry(1, 32, 32);
const earthMaterial = new THREE.ShaderMaterial({
  vertexShader: loadShader('vertexShader'),
  fragmentShader: loadShader('fragmentShader'),
  uniforms: {
    sunPosition: { value: new THREE.Vector3(5, 0, 0) }
  }
});
const earth = new THREE.Mesh(earthGeometry, earthMaterial);
scene.add(earth);

// Set up clock for animation
const clock = new THREE.Clock();

// Add controls for interaction
// const controls = new OrbitControls(camera, renderer.domElement);

// Update function
const update = () => {
  const delta = clock.getDelta();

  // Rotate the Earth
  earth.rotation.y += 0.2 * delta;

  // Update sun position for day/night effect
  const sunSpeed = 0.5;
  earthMaterial.uniforms.sunPosition.value.x = Math.cos(clock.elapsedTime * sunSpeed) * 5;
  earthMaterial.uniforms.sunPosition.value.y = Math.sin(clock.elapsedTime * sunSpeed) * 5;

  // Render the scene
  renderer.render(scene, camera);

  // Call update again on the next frame
  requestAnimationFrame(update);
};

// Start the animation loop
update();

// Handle window resize
window.addEventListener("resize", () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});
